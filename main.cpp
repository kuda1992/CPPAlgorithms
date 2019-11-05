#include <iostream>
#include <vector>
#include <map>
#include <string>

int minimum_number_of_coins(int money, std::vector<int> &coins) {

    std::vector<int> dp;

    for (int m = 0; m < money; m++) {
        dp[m] = 0;
        for (int i = 0; i < coins.size(); i++) {
            if (m > coins[i]) {

            }
        }
    }


}

std::vector<long> memo(100);


int naive_fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return naive_fibonacci(n - 1) + naive_fibonacci(n - 2);
}

int top_down_fibonacci(long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (memo[n] == 0)
        return memo[n] = top_down_fibonacci(n - 1) + top_down_fibonacci(n - 2);

    return memo[n];
}

int bottom_up_fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;


    std::vector<int> cache(n + 1);
    cache[0] = 1;

    for (int i = 2; i <= n; i++) {
        cache[i] = cache[i - 1] + cache[i - 2];
    }

    return cache[n] + cache[n - 1];

}


/*int main() {
    std::vector<int> coins = {6, 5, 1};
    std::cout << bottom_up_fibonacci(10) << std::endl;
    return 0;
}*/
