#include "iostream"
#include "string"
#include "vector"
#include <math.h>

template<typename T>
void swap(std::vector<T> &a, int x, int y) {
    T temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

template<typename T>
void selection_sort(std::vector<T> &a) {
    for (int i = 0; i < a.size(); i++) {
        int minIndex = i;
        for (int j = i + 1; j < a.size(); j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a, i, minIndex);
    }
}

template<typename T>
std::vector<T> merge(std::vector<T> &combined, std::vector<T> &first_half, std::vector<T> &second_half) {
    while (first_half.size() > 0 && second_half.size() > 0) {
        T first_half_element = first_half.front();
        T second_half_element = second_half.front();

        if (first_half_element <= second_half_element) {
            combined.push_back(first_half_element);
            first_half.erase(first_half.begin());
        } else {
            combined.push_back(second_half_element);
            second_half.erase(second_half.begin());
        }
    }

    while (first_half.size() > 0) {
        combined.push_back(first_half.front());
        first_half.erase(first_half.begin());
    }

    while (second_half.size() > 0) {
        combined.push_back(second_half.front());
        second_half.erase(second_half.begin());
    }
    return combined;
}


template<typename T>
void partition_vector_into_two_vectors(std::vector<T> &a, std::vector<T> &first_half, std::vector<T> &second_half, int partitionIndex) {
    for (int i = 0; i < a.size(); i++) {
        if (i < partitionIndex) {
            first_half.push_back(a[i]);
        } else {
            second_half.push_back(a[i]);
        }
    }
}

template<typename T>
std::vector<T> merge_sort(std::vector<T> &a) {

    if (a.size() == 1) {
        return a;
    }

    int partitionIndex = floor(a.size() / 2);

    // std::cout << "the partition size " << partitionIndex << std::endl;

    std::vector<T> first_half;
    std::vector<T> second_half;

    partition_vector_into_two_vectors(a, first_half, second_half, partitionIndex);

    first_half = merge_sort(first_half);
    second_half = merge_sort(second_half);

    std::vector<T> combined;

    return merge(combined, first_half, second_half);
}

template<typename T>
int partition(std::vector<T> &a, int l, int r) {
    T pivot = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= pivot) {
            ++j;
            swap(a, j, i);
        }
    }

    swap(a, l, j);
    return j;
}

template<typename T>
void quick_sort(std::vector<T> &a, int l, int r) {

    if (l >= r) {
        return;
    }

    int m = partition(a, l, r);

    quick_sort(a, l, m - 1);
    quick_sort(a, m + 1, r);
}


/*
int main() {
    std::vector<int> random_numbers = {3, 6, 7, 8, 1, 6, 8, 9, 1, 2, 5};

    quick_sort(random_numbers, 0, random_numbers.size());

    for (int i = 0; i < random_numbers.size(); i++) {
        std::cout << random_numbers[i] << std::endl;
    }
    return 0;
}
*/
