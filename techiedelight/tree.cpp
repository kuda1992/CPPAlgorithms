#include "iostream"
#include "algorithm"

template<typename T>
class node {
private:
    T value;
    node<T> *left;
    node<T> *right;


public:
    node() = delete; // prevent calling the default constructor;

    explicit node(const T &v) {
        value = v;
        left, right = nullptr;
    }

    void set_value(const T &v) {
        value = v;
    }


    T get_value() {
        return value;
    }

    void set_left(node<T> *n) {
        left = n;
    }

    node<T> *get_left() {
        return left;
    }

    void set_right(node<T> *n) {
        right = n;
    }

    node<T> *get_right() {
        return right;
    }


    void print() const {
        std::cout << value << std::endl;
    }
};


template<typename T>
class Tree {

private:
    node<T> *root;

    int height(node<T> *node) {

        int count = 0;

        while (node->get_left()) {
            count++;
            node = node->get_left();
        }
        return count;
    }


    int size(node<T> *node) {

        int count = 0;

        auto left = node;
        auto right = node;

        while (left->get_left()) {
            count++;
            left = node->get_left();
        }

        while (right->get_right()) {
            count++;
            right = node->get_right();
        }
        return count;
    }

    void in_order_traversal(node<T> *node) {

        if (node == NULL) {
            return;
        }

        in_order_traversal(node->get_left());

        // print the key;
        in_order_traversal(node->get_right());
    }

public:
    Tree() : root(NULL) {}

    ~Tree() {

    }

    void in_order_traversal() {
        in_order_traversal(root);
    }

    int height() {

        if (root == NULL) {
            return 0;
        }
        return 1 + std::max(height(root->get_left()), root(), height(root->get_right()));
    }

    int size() {

        if (root == NULL) {
            return 0;
        }
        return 1 + std::max(height(root->get_left()), root(), height(root->get_right()));
    }

};