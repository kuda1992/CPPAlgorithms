#include <iostream>
#include <vector>
#include <math.h>

template<typename T>
int LinearSearch(std::vector<T> &a, int low, int high, T key) {

    if (high < low) {
        return -1;
    }

    if (a[low] == key) {
        return low;
    }

    return LinearSearch(a, low + 1, high, key);
}


template<typename T>
int BinarySearch(std::vector<T> &a, int low, int high, T key) {

    if (high < low) {
        return -1;
    }

    int mid = floor(low + ((high - low) / 2));

    if (key == a[mid]) return mid;
    else if (key < a[mid]) return BinarySearch(a, low, mid - 1, key);
    else return BinarySearch(a, mid + 1, high, key);
}


template<typename T>
int BinarySearchIterative(std::vector<T> &a, int low, int high, T key) {

    while (low <= high) {
        int mid = floor(low + ((high - low) / 2));

        if (key == a[mid]) return mid;
        else if (key < a[mid]) high = mid - 1;
        else low = mid + 1;
    }
}

/*
int main() {

    std::vector<int> numbers = {1, 3, 4, 6, 7, 8};
    std::cout << BinarySearchIterative(numbers, 0, numbers.size(), 9) << std::endl;
    return 0;
}*/
