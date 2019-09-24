#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

/*
int minimum_edit_distance(const std::string &s1, const std::string &s2, int m, int n, std::vector<std::vector<int>> &cache) {

    if (m == 0)
        return m;

    if (n == 0)
        return n;

    // if the last are equal do nothing and recursively call (minimum edit distance)
    if (s1[m] == s2[n]) {
        cache[m][n] = minimum_edit_distance(s1, s2, m - 1, n - 1, cache);
        return cache[m][n];
    }

    int insert = 1 + minimum_edit_distance(s1, s2, m, n - 1, cache);
    int remove = 1 + minimum_edit_distance(s1, s2, m - 1, n, cache);
    int sub = 2 + minimum_edit_distance(s1, s2, m - 1, n - 1, cache);
    return (insert < remove ? (insert < sub ? insert : sub) : (remove < sub ? remove : sub));
}

int edit_distance(const std::string &str1, const std::string &str2) {

    int m = str1.length();
    int n = str2.length();

    std::vector<std::vector<int>> cache(m + 1);

    return minimum_edit_distance(str1, str2, m, n, cache);
}
*/


/*
int main() {
    std::string str1;
    std::string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;


}*/
