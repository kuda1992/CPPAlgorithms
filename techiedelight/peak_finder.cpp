#include "vector"
#include "iostream"


int peak_finder(std::vector<int> &A, int low, int high) {

    int mid = (high - low) / 2 + low;
    if (A[mid] < A[mid - 1]) {
        return peak_finder(A, low, mid - 1);
    } else if (A[mid] < A[mid + 1]) {
        return peak_finder(A, mid + 1, high);
    } else {
        return A[mid];
    }
}

/*
int main() {

    std::vector<int> numbers = {1, 2, 3, 4, 6, 7, 8, 9};

    std::cout << "The peak is " << peak_finder(numbers, 0, numbers.size()) << std::endl;

}*/
