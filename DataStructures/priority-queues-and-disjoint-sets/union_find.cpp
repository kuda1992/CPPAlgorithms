#include <iostream>

template<typename T>
class UnionFind {

private:
    T *data;
    int currentSize;
    int size;
    int *subSetSizes;

    int root(int i) {

        while (data[i] != i) {
            data[i] = data[data[i]];
            i = data[i];
        }

        return i;
    }

public:
    UnionFind(int size) {
        this->size = size;
        data = new T[size];
        subSetSizes = new int[size];

        for (int i = 0; i < size; ++i) {
            subSetSizes[i] = 1;
        }
        currentSize = 0;
    }

    void insert(T item) {

        if (currentSize >= size) {
            return;
        }
        data[currentSize++] = item;
    }

    void unionItems(T a, T b) {

        int rootA = root(a);
        int rootB = root(b);


        if (subSetSizes[rootA] < subSetSizes[rootB]) {
            data[rootA] = data[rootB];
            subSetSizes[rootB] += subSetSizes[rootA];
        } else {
            data[rootB] = data[rootA];
            subSetSizes[rootA] += subSetSizes[rootB];
        }

        data[rootA] = data[rootB];

    }

    bool find(T a, T b) {
        if (root(a) == root(b)) return true;
        return false;
    }

    int findPrint(int a) {
        std::cout << data[a] << std::endl;
    }

    void printItems() {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }

        std::cout << "\n";
    }

};