#include "iostream"
#include "vector"
#include "algorithm"


class HeapBuilder {

private:
    std::vector<int> data_;
    std::vector<std::pair<int, int>> swaps_;

    void write_response() const {

        std::cout << swaps_.size() << " \n";

        for (const auto swap: swaps_) {
            std::cout << swap.first << " " << swap.second << "\n";
        }
    }

    /*
     * Sink element A[i] to maintain min-heap property
     *
     * Choose the smaller of the left/right child, if any.
     * Terminate is A[i] is already less than children
     * Swap with the smaller child and record the swap
     * Trace A[i] downwards to the smaller children
     * Terminate is A[i] has no children
     *
     */
    void sink(int i) {

        int n = data_.size();

        // while A[i] has at least one left child

        while (i * 2 + 1 < n) {
            int j = i * 2 + 1;
            // decide if the right child exists and is the smaller child
            j = (j + 1 < n && data_[j + 1] < data_[j]) ? j + 1 : j;

            if (data_[i] <= data_[j]) return;

            swaps_.emplace_back(i, j);

            std::swap(data_[i], data_[j]);

            i = j;

        }
    }

    void read_data() {

        int n;
        std::cin >> n;

        data_.resize(n);

        for (int i = 0; i < n; i++) {
            std::cin >> data_[i];
        }

    }

    void generate_swaps_fast() {
        swaps_.clear();

        for (int i = data_.size() / 2; i >= 0; i--)
            sink(i);
    }


    void generate_swaps() {
        swaps_.clear();

        // the following naive implementation just sorts the given sequence using selection sort algorithm
        // and saves the resulting sequence of swaps
        // this turns the given array into a heap
        // but in the worst case gives a quadratic number of swaps

        for (int i = 0; i < data_.size(); i++) {
            for (int j = i + 1; j < data_.size(); j++) {
                if (data_[i] > data_[j]) {
                    std::swap(data_[i], data_[j]);
                    swaps_.emplace_back(i, j);
                }
            }
        }
    }

public:
    void solve() {

        read_data();
        generate_swaps_fast();
        write_response();
    }
};

/*
int main() {

    std::ios_base::sync_with_stdio(false);

    HeapBuilder heapBuilder;

    heapBuilder.solve();

    return 0;
}*/
