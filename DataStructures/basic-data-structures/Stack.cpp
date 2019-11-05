#include <exception>
#include <cmath>
#include <stdexcept>
#include <iostream>

template<typename T>
class Stack {

private:
    T *data;
    static const unsigned int initialSize = 100;
    unsigned int s; // size
    unsigned int c; // capacity

public:
    Stack() {
        s = 0;
        data = new T[initialSize];
        c = initialSize;
    };

    void resize(int newCapacity) {

        if (newCapacity < s) {
            throw std::length_error("size entered smaller than current size");
        }
        T *temp = new T[s];

        for (int i = 0; i < s; ++i) {
            temp[i] = data[i];
        }

        delete[] data;
        data = temp;
        c = newCapacity;
    }

    T pop() {

        //remove the element from the array
        // go to the last element of the array and deference the pointer
        // this has O(n) complexity
        if (s == 0) {
            throw std::length_error("no elements in the stack");
        }
        T temp = data[s];
        data[s] = NULL;
       /// delete data[s];

        s--;

        // TODO: implement the resize if size becomes too small than capacity, this allows us to save space

        return temp;
    }


    void push(T item) {

        // if the size is greater than capacity increase the size of the array
        if (s > c) {
            int resizeFactor = std::floor(c + (0.25 * c));
            resize(resizeFactor);
        }

        data[s] = item;

        std::cout << "added " << data[s] << " to the array \n";

        s++;
    }


    unsigned int size() const {
        return s;
    }

    unsigned int capacity() const {
        return c;
    }

    T begin() {
        return data[0];
    }

    T end() {
        return data[s];
    }

};
