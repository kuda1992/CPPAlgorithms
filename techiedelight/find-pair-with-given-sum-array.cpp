#include <iostream>
#include <algorithm>


void find_pair(int arr[], int n, int sum) {

    // sort the array in ascending order
    std::sort(arr, arr + n);

    // maintain two end indices pointing to end-points of the array
    int low = 0;
    int high = n - 1;

    // loop through till low is less than high

    while (low < high) {
        // pair found
        if (arr[low] + arr[high] == sum) {
            std::cout << "Pair found " << arr[low] << ", " << arr[high] << std::endl;
            return;
        }

        // increment low index is total is less than the desired sum
        // decrement high index if the total is greater than the desired sum
        (arr[low] + arr[high]) < sum ? low++ : high--;
    }

    std::cout << "Pair not found" << std::endl;

}


/*int main() {

    int arr[] = {8, 7, 2, 5, 2, 3, 1};
    int sum = 10;

    // length of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    find_pair(arr, n, sum);

}*/

