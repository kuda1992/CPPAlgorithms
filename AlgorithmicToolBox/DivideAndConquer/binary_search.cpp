#include "iostream"
#include "cassert"
#include "vector"
#include <math.h>
#include <algorithm>


long binary_search(const std::vector<long> &a, long x) {

    long left = 0, right = a.size();
    while (left <= right) {
        long mid = (right - left) / 2 + left;

        if (x < a[mid]) right = mid - 1;
        else if (x > a[mid]) left = mid + 1;
        else return mid;
    }
    return -1;
}

int linear_search(const std::vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}


/*
int main() {
    long n;
    std::cin >> n;
    std::vector<long> a(n);

    for (long &i : a) {
        std::cin >> i;
    }

    std::sort(a.begin(), a.end(), [](const long a, const long b) { return a < b; });

    long m;
    std::cin >> m;
    std::vector<long> b(m);

    for (auto i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    for (long i = 0; i < m; ++i) {
        std::cout << binary_search(a, b[i]) << ' ';
    }
}
*/
