#include <iostream>
#include <cmath>


long long gcd_fast2(int a, int b) {
    if (a == 0)
        return b;
    return gcd_fast2(b % a, a);
}

long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long) a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long) a * b;
}

long long lcm_better(int a, int b) {
    return ((long) a * b) / gcd_fast2(a, b);
}

/*
int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << lcm_better(a, b) << std::endl;
    return 0;
}
*/
