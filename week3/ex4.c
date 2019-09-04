#include <stdio.h>

int partition(int *array, int lo, int hi) {
    int pivot = array[lo + (hi - lo) / 2];
    while (1) {
        while (array[lo] < pivot) {lo = lo + 1;}
        while (array[hi] > pivot) {hi = hi - 1;}

        if (lo >= hi) {return hi;}

        int temp = array[lo];
        array[lo] = array[hi];
        array[hi] = temp;

        lo += 1;
        hi += 1;
    }
}
void _quicksort(int array[], int lo, int hi) {
    if (lo < hi) {
        int pivot = partition(array, lo, hi);
        _quicksort(array, lo, pivot - 1);
        _quicksort(array, pivot + 1, hi);
    }
}
void quicksort(int array[], int size) {
    _quicksort(array, 0, size-1);
}

int main() {
    int a[10] = {7, 1, 54, 2, 13, 5, 9, 6, 0, -19};
    quicksort(a, 10);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}