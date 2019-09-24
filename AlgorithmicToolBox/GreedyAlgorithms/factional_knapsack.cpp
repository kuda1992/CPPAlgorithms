#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>


struct Item {
    int weight;
    int value;
    double value_per_unit;

    Item(int _value, int _weight) {
        value = _value;
        weight = _weight;

        value_per_unit = value / (double) weight;
    }
};

void addItems(std::vector<Item> &items, const std::vector<int> &values, const std::vector<int> &weights, int N) {

    for (int i = 0; i < N; i++) {
        Item item = {values[i], weights[i]};
        items.push_back(item);
    }
}


double get_optimal_value(int capacity, const std::vector<int> weights, const std::vector<int> values) {
    double value = 0.0;
    std::vector<Item> items;
    addItems(items, values, weights, values.size());

    std::sort(items.begin(), items.end(), [](const Item &a, const Item &b) { return a.value_per_unit > b.value_per_unit; });
    int i = 0;

    while (i < items.size() && capacity > 0) {

        int fraction = std::min(items[i].weight, capacity);
        value += items[i].value_per_unit * fraction;
        capacity -= fraction;
        i++;
    }
    return value;
}


/*
int main() {
    int n;
    int capacity;

    std::cin >> n >> capacity;

    std::vector<int> values(n);
    std::vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }
    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
}
*/

