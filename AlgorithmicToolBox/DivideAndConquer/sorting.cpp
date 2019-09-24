#include <iostream>
#include <vector>
#include <cstdlib>

void partition(std::vector<int> &a, int l, int r, int &i, int &j) {

    i = l - 1;
    j = r;

    int p = l - 1;
    int q = r;

    int v = a[r];

    while (true) {

        // from left to right find the first element greater than or equal to v. this loop will definitely terminate as v is the last element
        while (a[++i] < v);

        // from right, find the element smaller than or equal to v;
        while (v < a[--j]) {
            if (j == i) break;
        }

        // If i and j cross, then we are done
        if (i >= j) break;

        std::swap(a[i], a[j]);

        // Move all same left occurrence of pivot to beginning of
        // array and keep count using p
        if (a[i] == v) {
            p++;
            std::swap(a[p], a[i]);
        }

        // Move all same right occurrence of pivot to end of array
        // and keep count using q
        if (a[j] == v) {
            q--;
            std::swap(a[j], a[q]);
        }
    }

    // Move pivot element to its correct index
    std::swap(a[i], a[r]);

    // Move all left same occurrences from beginning
    // to adjacent to arr[i]
    j = i - 1;
    for (int k = l; k < p; k++, j--)
        std::swap(a[k], a[j]);

    // Move all right same occurrences from end
    // to adjacent to arr[i]
    i = i + 1;
    for (int k = r - 1; k > q; k--, i++)
        std::swap(a[i], a[k]);
}

void randomized_quick_sort(std::vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int i;
    int j;

    // note i and j are passed are reference;
    // Note that i and j are passed as reference
    partition(a, l, r, i, j);

    // Recur
    randomized_quick_sort(a, l, j);
    randomized_quick_sort(a, i, r);
}

/*
int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}*/
