#include <stdio.h>
#define C 8
#define PAGE_FRAMES 10
#define NOT_IN_MEMORY -1


void append(int arr[], int R) {
    for (int i = 0; i < C-1; ++i) {
        arr[i+1] = arr[i];
    }
    arr[0] = R;
}
// returns positive number if arr1 is "greater" than arr2,
// negative number if arr1 is "less" than arr2,
// 0 if they are equal
int cmp(int arr1[], int arr2[]) {
    for (int i = 0; i < C; ++i) {
        if (arr1[i] != arr2[i]) {
            return arr1[i] - arr2[i];
        }
    }
    return 0;
}


typedef struct page {
    int ref[C]; // the reference "history" over C clock ticks
    int R;      // the R bit
    int pnum;   // page number
} page;


page physical_memory[1000];
page main_memory[PAGE_FRAMES];



void load_page(int page, int to) {
    main_memory[to] = physical_memory[page];
}

void update_pages(int pnum) {
    main_memory[pnum].R = 1;
    append(main_memory[pnum].ref, main_memory[pnum].R);
    for (int i = 0; i < PAGE_FRAMES; ++i) {
        if (i != pnum) {
            main_memory[i].R = 0;
            append(main_memory[i].ref, main_memory[i].R);
        }
    }
}

void swap_page(int pnum) {

    // searching for the suitable page
    int min = 0;
    for (int i = 1; i < PAGE_FRAMES; ++i) {
        if (cmp(main_memory[i].ref, main_memory[min].ref) < 0) {
            min = i;
        }
    }

    // swapping it out
    main_memory[min].R = 0;
    page temp = main_memory[min];
    main_memory[min] = physical_memory[pnum];
    physical_memory[pnum] = temp;
    update_pages(min);

}

int main(void) {
    FILE* in = fopen("input.txt", "r");

    for (int i = 0; i < PAGE_FRAMES; ++i) { // initializing main memory
        main_memory[i].pnum = NOT_IN_MEMORY;
        main_memory[i].R = 0;
        for (int j = 0; j < C; ++j) {
            main_memory[i].ref[j] = 0;
        }
    }

    for (int i = 0; i < 1000; ++i) { // initiailzing physical memory
        physical_memory[i].pnum = i;
        physical_memory[i].R = 0;
        for (int j = 0; j < C; ++j) {
            physical_memory[i].ref[j] = 0;
        }
    }

    int hitc = 0, missc = 0, pref;

    while (fscanf(in, "%d", &pref) != EOF) { // processing references

        int i = 0;
        for (i; i < PAGE_FRAMES; ++i) {
            if (main_memory[i].pnum == pref) {
                break;
            }
        }

        if (i == PAGE_FRAMES) { // if page was not found
            ++missc;
            int j = 0;
            for (j; j < PAGE_FRAMES; ++j) { // looking for empty place
                if (main_memory[j].pnum == NOT_IN_MEMORY) {
                    load_page(pref, j);
                    update_pages(j);
                    break;
                }
            }
            if (j == PAGE_FRAMES) { // if no empty place is found
                swap_page(pref);
            }
        }
        else { // if page was found
            ++hitc;
            update_pages(i);
        }
    }
    printf("Hit/miss ratio: %d/%d", hitc, missc);
    fclose(in);
    return 0;
}