#include "iostream"


void print_array(int arr[], int n) {

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}

// in place merge for two sorted arrays x[] and y[]
// invariant: x[] and y[] are sorted at any point
void merge(int X[], int Y[], int m, int n) {

    // consider each element x[i] of array x and ignore the element
    // if it is already in correct order else swap it with next smaller
    // element which happens to first element Y
    for (int i = 0; i < m; i++) {

        // compare the first element of X[] with the first element of Y[]
        if (X[i] > Y[0]) {
            std::swap(X[i], Y[0]);
            int first = Y[0];

            // move Y[0] to its correct position to maintain sorted
            // order of Y[]: Note Y[] is already sorted
            int k;
            for(k = 1; k < n && Y[k] < first; k++) {
                Y[k - 1] = Y[k];
            }
        }
    }
}

/*
int main() {


    int X[] = {1, 4, 7, 8, 10};
    int Y[] = {2, 3, 9};

    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);

    merge(X, Y, m, n);

    std::cout << "X: ";
    print_array(X, m);
    std::cout << "Y: ";
    print_array(Y, n);

    return 0;
}*/
