#include <iostream>
#include <numeric>
#include "vector";

void print_vector(std::vector<int> &v) {
    // lambda expression to print vector
    for_each(v.begin(), v.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;

}

std::vector<int>::iterator find_numbers_greater_than_four(std::vector<int> &v) {
    return find_if(v.begin(), v.end(), [](int x) { return x > 4; });
}

void sort_asc(std::vector<int> &v) {

    sort(v.begin(), v.end(), [](const int &a, const int &b) { return a > b; });
}

void sort_desc(std::vector<int> &v) {

    sort(v.begin(), v.end(), [](const int &a, const int &b) { return a < b; });
}

int add(std::vector<int> &v) {
    return std::accumulate(v.begin(), v.end(), 0, [](int a, int b) { return a + b; });
}


/*
int main() {


    std::vector<int> v{4, 1, 3, 5, 2, 3, 1, 7};

    sort_asc(v);

    print_vector(v);

    std::vector<int>::iterator p = find_numbers_greater_than_four(v);

    std::cout << "the first number greater than four " << *p << std::endl;

    std::cout << "the total is " << add(v) << std::endl;
}*/
