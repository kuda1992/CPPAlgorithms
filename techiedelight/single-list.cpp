#include "iostream"
#include "string"


template<typename T>
class node {
private:
    T value;
    node<T> *left;


public:
    node() = delete; // prevent calling the default constructor;

    explicit node(const T &v) {
        value = v;
        left = nullptr;
    }

    void set_value(const T &v) {
        value = v;
    }


    T get_value() {
        return value;
    }

    void set_next(node<T> *n) {
        left = n;
    }

    node<T> *get_next() {
        return left;
    }

    void print() const {
        std::cout << value << std::endl;
    }
};


template<typename T>
class SinglyLinkedList {

private:
    node<T> *head;
    node<T> *tail;

public:
    SinglyLinkedList() : head(NULL), tail(NULL) {}

    ~SinglyLinkedList() {
        // free all the nodes;
        node<T> *current = head;

        while (current) {
            node<T> *next = current->get_next();
            delete (current);
            current = next;
        }
    }

    void push_front(const T &value) {

        auto *node = new ::node<T>(value);

        if (!head) {
            // special case list is empty;
            head = node;
            tail = node;
        } else {
            node->set_next(head);
            head = node;
        }
    }

    T pop_front() {

        node<T> *node = head;

        head = head->get_next();

        return node->get_value();
    }

    T get_front() {
        return head->get_value();
    }

    T get_back() {
        node<T> *node = head;

        while (node) {
            node = node->get_next();
        }

        return node->get_value();

    }

    int length() const {

        node<T> *node = head;
        int count = 0;

        while (node) {
            ++count;
            node = node->get_next();
        }

        return count;
    }

    void push_back(const T &value) {

        auto *node = new ::node<T>(value);

        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->set_next(node);
            tail = node;
        }
    }


    T pop_back() {

        node<T> *node = head;
        // if there is only element
        if (head == tail) {
            // delete (head);
            head = NULL;
            tail = NULL;

        } else {

            while (node->get_next()) {
                node = node->get_next();
            }

            node->set_next(nullptr);
            // delete (tail);
            tail = node;
        }
        return node->get_value();
    }

    void print() const {

        node<T> *node = head;

        while (node) {
            node->print();
            node = node->get_next();
        }
    }
};


/*
int main() {

    SinglyLinkedList<std::string> list;

    list.push_back("kuda");
    list.push_back("thomas");
    list.push_front("tanya");
    //list.pop_front();
    auto remove_last = list.pop_back();

    list.print();

    std::cout << "the count is " << list.length() << std::endl;
    std::cout << "the last element " << remove_last << std::endl;

    //std::cout << "the front is " << list.get_front() << std::endl;
    // list.get_back();
    // std::cout << "the back is " << list.get_back() << std::endl;


}*/
