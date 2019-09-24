#include <iostream>
#include <vector>

double get_change(int m) {
    int total = 0;
    std::vector<int> denominations = {10, 5, 1};

    while (m > 0) {
        int i = 0;

        while (i <= 2 && denominations[i] > m) i++;

        m -= denominations[i];
        total++;
    }
    return total;
}

/*int main() {
    int m;

    std::cin >> m;
    std::cout << get_change(m) << std::endl;
}*/

