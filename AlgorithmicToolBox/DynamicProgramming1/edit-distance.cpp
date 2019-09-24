#include <iostream>
#include <string>
#include <vector>


int minimum_edit_distance(const std::string &s1, const std::string &s2, int m, int n, std::vector<std::vector<int>> &cache) {

    if (m == 0)
        return m;

    if (n == 0)
        return n;


    for(int j = 1; j <= n; j++) cache[0][j] = j;
    /*for(int i = 1; i <= m; i++) cache[i][0] = i;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            int insertion = cache[i][j - 1] + 1,
                    deletion  = cache[i - 1][j] + 1,
                    mismatch  = cache[i - 1][j - 1] +
                                (s1.(i - 1) == s2.charAt(j - 1) ? 0 : 1);
            // BZ: the ith char should have index i - 1
            table[i][j] = Math.min(insertion,
                                   Math.min(deletion, mismatch));
        }
    }
    return table[m][n];*/
}

int edit_distance(const std::string &str1, const std::string &str2) {

    int m = str1.length();
    int n = str2.length();

    std::vector<std::vector<int>> cache(m + 1);

    return minimum_edit_distance(str1, str2, m, n, cache);
}


/*
int main() {
    std::string str1;
    std::string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}
*/


