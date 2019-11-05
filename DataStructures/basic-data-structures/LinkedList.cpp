#include <iostream>

template<typename T>
class LinkedList {

private:

    struct Node {
        T data;
        Node *next;

        Node(T item) : data(item), next(nullptr) {};

    };

    Node *head;
    Node *tail;
    unsigned int s;

public:

    LinkedList() {
        head = nullptr;
        tail = nullptr;
        s = 0;
    }

    void addFirst(T item) {
        Node *node = new Node(item);


        if (head) {
            node->next = head;
            head = node;
        } else {
            node->next = head;
            head = node;
            tail = node;
        }
        s++;
    }

    void addLast(T item) {

        Node *node = new Node(item);

        if (head) {
            tail->next = node;
            tail = node;
        } else {
            head = node;
            tail = node;
        }

        s++;
    }

    T removeFirst() {

        if (head) {
            T temp = head->data;
            head = head->next;
            s--;
            return temp;
        }

        head = tail = nullptr;
        return NULL;
    }

    T find(T item) const {
        T result = NULL;
        if (head) {
            Node *current = head;

            if (current->data == item) {
                return current->data;
            }

            while (current) {
                if (current->data == item) {
                    result = current->data;
                    break;
                }
                current = current->next;
            }

            return result;

        }

        return result;

    }

    T operator[](T item) const {
        return find(item);
    }

    T remove(T item) {

        if (head) {

            Node *previous = nullptr;
            Node *current = head;

            while (current->data != item && current->next) {
                previous = current;
                current = current->next;
            }

            if (current->data == item) {
                T temp = current->data;
                if (previous) {
                    previous->next = current->next;
                    delete current;
                } else {
                    delete current;
                }

                s--;

                return temp;

            }
            return NULL;

        }

        return NULL;
    }

    T removeLast() {

        if (head) {
            T temp = tail->data;
            Node *previous = nullptr;
            Node *current = head;
            while (current->next) {
                previous = current;
                current = current->next;
            }

            if (previous) {
                previous->next = nullptr;
            } else {
                head = previous;
            }
            tail = previous;
            s--;
            return temp;
        }

        return NULL;
    }

    unsigned int size() {
        return s;
    }
};