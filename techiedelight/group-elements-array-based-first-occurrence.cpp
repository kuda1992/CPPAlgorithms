#include "iostream"
#include "unordered_map"


/*
 * Group an unsorted array  of integers containing many duplicates elements, rearrange the given array such that same elements appears together and relative order
 * of the first occurrence of each element remains unchanged
 *
 *  For example
 *
 *  Input: {1,2,3,1,2,1}
 *  Output: {1,1,1,2,2,3}
 *
 *  Input: {5,4,5,5,3,1,2,2,4}
 *  Output: {5,5,5,4,4,3,1,2,2}
 *
 *
 *  The idea is to use hashing in this data structure. We store the frequency of each element present in the array in a map.
 *  Then we transverse the input array and for each element A[i], there are two possible cases
 *
 *  1. A[i] exists in the map, then this is the first occurrence of A[i] in the input array; We print the A[i] k times where is the frequency of A[i] in the input array (stored in the map). And we finally delete A[i] from the map
 *  2. if A[i] is not present in the map, then this is repeated occurrence of A[i], and move to the next element
 *
 *
 *
 */

// function to group elements of the given array based of first occurrence
void rearrange(int A[], int n) {

    // create an empty map to store frequency of each element
    std::unordered_map<int, int> frequency;

    // transverse the input array and update frequency of each element
    for (int i = 0; i < n; i++)
        frequency[A[i]]++;

    for (int i = 0; i < n; i++) {

        //if A[i] exists in the map (first occurrence) of A[i]
        if (frequency.find(A[i]) != frequency.end()) {

            // print A[i] n times where n = frequency[A[i]]
            int n = frequency[A[i]];

            while (n--) {
                std::cout << A[i] << " ";
            }

            // delete element from the map for it wont get processed again
            frequency.erase(A[i]);
        }
    }
}


/*
int main() {
    int A[] = {5, 4, 5, 5, 3, 1, 2, 2, 4};

    int n = sizeof(A) / sizeof(A[0]);

    rearrange(A, n);

    return 0;
}*/
