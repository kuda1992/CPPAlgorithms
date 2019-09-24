#include "iostream"
#include "vector"
#include "algorithm"
#include "stdexcept"


// Data structure for Max Heap

class PriorityQueue {
private:
    // vector to store heap elements
    std::vector<int> A;

    // return the parent of the heap data structure
    // dont call this function if its already the root node
    static int parent(int i) {
        return (i - 1) / 2;
    }

    // return the left child of A[i]
    int LEFT(int i) {
        return (2 * i + 1);
    }

    // return the right child of A[i]
    int RIGHT(int i) {
        return (2 * i + 2);
    }


    // recursive heapify the algorithm
    void heapify_up(int index) {

        // check if node at index i and its parent violates
        // the heap property
        if (index && A[PriorityQueue::parent(index)] < A[index]) {
            std::swap(A[index], A[PriorityQueue::parent(index)]);

            // call heapify on the parent
            heapify_up(PriorityQueue::parent(index));
        }
    }

    // recursive heapify down algorithm
    // node at index i and its two direct children
    // violates the heap property
    void heapify_down(int i) {

        // get the left child and right child at index i
        int left = LEFT(i);
        int right = RIGHT(i);

        int largest = i;

        // compare A[i] with its left and right child
        // and find the largest value
        if (left < size() && A[left] > A[i])
            largest = left;

        if (right < size() && A[right] > A[largest])
            largest = right;

        // swap with the child having greater value and call heapify down on the child
        if (largest != i) {
            std::swap(A[i], A[largest]);
            heapify_down(largest);
        }
    }

public:
    // returns the size of the heap
    unsigned int size() const {
        return A.size();
    }

    // function to check if the heap is empty of not
    bool empty() const {
        return A.empty();
    }

    // insert a key into the heap
    void push(const int key) {

        // insert new element at the end of the key
        A.push_back(key);

        // get element index and call heapify_up procedure
        int index = size() - 1;

        heapify_up(index);
    }

    // function to remove element with highest priority (present at root)
    void pop() {

        try {

            // if heap has no elements throw an exception
            if (size() == 0) {
                throw std::out_of_range("Vector<int>::at() : index is out of range (Heap underflow)");
            }

            // replace the root of the heap with the last element
            A[0] = A.back();
            A.pop_back();

            // call heapify_down on the root node;
            heapify_down(0);
        } catch (const std::out_of_range &outOfRange) {
            std::cout << "\n" << outOfRange.what() << std::endl;
        }
    }


    // function to return the element with highest priority (present at the root)
    int top() const {

        try {
            // if heap has no elements throw an exception
            if (size() == 0) {
                throw std::out_of_range("Vector<int>::at() : index is out of range (Heap underflow)");
            }
            return A.at(0);

        } catch (const std::out_of_range &outOfRange) {
            std::cout << "\n" << outOfRange.what() << std::endl;
        }
    }
};


/*
int main () {

    PriorityQueue priorityQueue;

    priorityQueue.push(3);
    priorityQueue.push(2);
    priorityQueue.push(15);

    std::cout << "The size of the priority queue is " << priorityQueue.size() << std::endl;

    std::cout << priorityQueue.top() << " " ;

    priorityQueue.pop();

    std::cout << priorityQueue.top() << " " ;

    priorityQueue.pop();


    priorityQueue.push(5);
    priorityQueue.push(4);
    priorityQueue.push(45);

    std::cout << std::endl << "Size is " << priorityQueue.size() << std::endl;





}*/
