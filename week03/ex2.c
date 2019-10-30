#include <stdio.h>

void bubblesort(int* a, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int a[10] = {7, 1, 54, 2, 13, 5, 9, 6, 0, -19};
    bubblesort(a, 10);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", a[i]);
    }
}
