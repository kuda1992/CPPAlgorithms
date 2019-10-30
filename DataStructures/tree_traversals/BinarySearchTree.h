

#ifndef ALGORITHMS_BINARYSEARCHTREE_H
#define ALGORITHMS_BINARYSEARCHTREE_H

#include <list>
#include <iostream>
#include <cmath>
#include <functional>

template<typename Comparable, typename Comparator = std::less<Comparable>>
class BinarySearchTree {

public:
    BinarySearchTree();

    // construct an empty binary search tree
    BinarySearchTree(const std::list<Comparable> &);

    ~BinarySearchTree();

    void construct(const std::list<Comparable> &);

    const Comparable findMin() const;

    const Comparable findMax() const;

    bool contains(const Comparable *) const;

    bool isEmpty() const;

    void insert(Comparable *);

    void insert(Comparable);

    const Comparable get(const Comparable *) const;

    const Comparable get(const Comparable) const;

    const Comparable operator[](const Comparable *) const;

    const Comparable operator[](const Comparable) const;

    void remove(const Comparable *);

    void remove(const Comparable);

    size_t getSize() const;

    int getHeight() const;

    bool isBalanced() const;

    void print() const;


private:

    struct TreeNode {

        const Comparable element; // address of the element
        TreeNode *left; // address of the right element
        TreeNode *right; // address of the left element
        TreeNode *parent;
        size_t height;

        TreeNode(const Comparable el, TreeNode *l, TreeNode *r, TreeNode *p) : element(el), left(l), right(r), parent(p) {

        }
    };

    TreeNode *root;


    size_t size;

    int height;

    bool balanced;

    Comparator isLessThan;

    // BinarySearchTree(const BinarySearchTree &); // uncopyable copy constructor;

    // BinarySearchTree &operator=(const BinarySearchTree &); // uncopyable copy assignment;

    TreeNode *findMin(TreeNode *) const;

    TreeNode *findMax(TreeNode *) const;

    int updateHeight(TreeNode *treeNode, int leftHeight, int rightHeight);

    bool contains(const Comparable *, TreeNode *) const;

    int findHeight(TreeNode *) const;

    TreeNode *traverseUp(TreeNode *t);

    bool isLeaf(TreeNode *t) const;

    bool isFull(TreeNode *) const;

    void print(TreeNode *) const; // print recursively

    void destroyTree(TreeNode *);

    template<typename T>
    T max(T &x, T &y) {
        return x > y ? x : y;
    }
};


#endif //ALGORITHMS_BINARYSEARCHTREE_H
