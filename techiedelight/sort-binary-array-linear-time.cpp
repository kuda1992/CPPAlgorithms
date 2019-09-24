#include <stdio.h>

int sort(int arr[], int n) {

    // count the number of zeros
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            zeros++;
    }

    // put zeros at the beginning of the array
    int k = 0;
    while (zeros--) {
        arr[k++] = 0;
    }

    // fill the remaining elements by 1
    while (k < n) {
        arr[k++] = 1;
    }
}


/*
int main() {

    int A[] = {0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0,0, 0,0};

    int n = sizeof(A) / sizeof(A[0]);

    sort(A, n);

    // print the rearranged array
    for (int i = 0; i < n; i++)
        printf("%d", A[i]);

}*/
