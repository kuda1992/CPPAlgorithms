

#include "BinarySearchTree.h"
#include <list>
#include <iostream>
#include <cmath>
#include <functional> //less<T> <-> operator<

template<typename Comparable, typename Comparator>
BinarySearchTree<Comparable, Comparator>::BinarySearchTree() {
    size = 0;
    balanced = 1;
    height = 0;
    root = NULL;
}


template<typename Comparable, typename Comparator>
BinarySearchTree<Comparable, Comparator>::BinarySearchTree(const std::list<Comparable> &data) {

    for (Comparable &item: data) {
        insert(item);
    }
}


template<typename Comparable, typename Comparator>
void BinarySearchTree<Comparable, Comparator>::destroyTree(BinarySearchTree<Comparable, Comparator>::TreeNode *t) {

    if (t != NULL) {
        destroyTree(t->left);
        destroyTree(t->right);

        if (t->left == NULL and t->right == NULL) {
            delete t;
        }
    }
}

template<typename Comparable, typename Comparator>
BinarySearchTree<Comparable, Comparator>::~BinarySearchTree() {
    destroyTree(root);
}

template<typename Comparable, typename Comparator>
size_t BinarySearchTree<Comparable, Comparator>::getSize() const {
    return size;
}


template<typename Comparable, typename Comparator>
void BinarySearchTree<Comparable, Comparator>::insert(Comparable item) {
    // item does not exist in binary search tree

    if (!contains(&item)) {
        int leftLeafHeight = 0;
        int rightLeafHeight = 0;

        if (root != NULL) {
            leftLeafHeight = findHeight(root->left);
            rightLeafHeight = findHeight(root->right);
        }

        // if root is not null traverse down the tree till you find a leaf
        if (root != NULL) {
            TreeNode *leaf = root;
            // while the right side of the leaf is not null or the left sid of the tree is not null check if the item is less than the leaf
            // if the item is less than the left leaf go to the right of the tree
            // conversely if the item is larger than the tree of to the right of the tree

            while (leaf && (leaf->left || leaf->right)) {
                if (isLessThan(item, leaf->element) && leaf->left != NULL) { // item is less than current item
                    leaf = leaf->left; // traverse to the left of the tree
                } else {
                    if (leaf->right == NULL) break; // if right leaf is null break out the loop
                    leaf = leaf->right; // traverse to the right of the tree;
                }
            }

            if (isLessThan(item, leaf->element)) {
                leaf->left = new TreeNode{item, NULL, NULL, leaf}; // insert the item to the left side of the tree
                leaf->left->height = 0;
                updateHeight(leaf->left, leftLeafHeight, rightLeafHeight);
            } else {
                leaf->right = new TreeNode{item, NULL, NULL, leaf}; // insert the item to the right side of the tree
                leaf->right->height = 0;
                updateHeight(leaf->right, leftLeafHeight, rightLeafHeight);
            }

            size++;
        } else {
            root = new TreeNode{item, NULL, NULL, NULL};
            root->height = 0;
            size++;
        }
        // rebalance the tree

    }
}

template<typename Comparable, typename Comparator>
int BinarySearchTree<Comparable, Comparator>::findHeight(BinarySearchTree<Comparable, Comparator>::TreeNode *item) const {

    if (item == NULL) return -1; // no height;

    int leftHeight = findHeight(item->left);
    int rightHeight = findHeight(item->right);

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

template<typename Comparable, typename Comparator>
bool BinarySearchTree<Comparable, Comparator>::contains(const Comparable *item) const {
    return contains(item, root);
}

template<typename Comparable, typename Comparator>
int BinarySearchTree<Comparable, Comparator>::updateHeight(BinarySearchTree<Comparable, Comparator>::TreeNode *treeNode, int leftHeight, int rightHeight) {

    if ((treeNode->left == treeNode->parent->left && leftHeight > rightHeight) || (treeNode->right == treeNode->parent->right && rightHeight > leftHeight)) {
        treeNode = treeNode->parent;
        while (treeNode->parent != NULL) {
            treeNode->height = treeNode->height + 1;
            treeNode = treeNode->parent;
        }
        treeNode->height = treeNode->height + 1;
    }

    root->height = findHeight(root);
}

template<typename Comparable, typename Comparator>
bool BinarySearchTree<Comparable, Comparator>::contains(const Comparable *item, BinarySearchTree<Comparable, Comparator>::TreeNode *root) const {

    if (root == NULL) return false; // if root is null item is not in binary tree

    if (*item == root->element) return true;

    if (isLessThan(*item, root->element)) { // item is less than current node check the left side of the tree
        return contains(item, root->left);
    }

    if (isLessThan(root->element, *item)) { // item is larger than the current node check the right side of the tree
        return contains(item, root->right);
    }

    return false; // no element found
}

template<typename Comparable, typename Comparator>
bool BinarySearchTree<Comparable, Comparator>::isLeaf(BinarySearchTree<Comparable, Comparator>::TreeNode *t) const {
    return t != NULL && t->right == NULL && t->left == NULL;
}

template<typename Comparable, typename Comparator>
bool BinarySearchTree<Comparable, Comparator>::isFull(BinarySearchTree<Comparable, Comparator>::TreeNode *t) const {
    return t->right != NULL && t->left != NULL;
}


template<typename Comparable, typename Comparator>
void BinarySearchTree<Comparable, Comparator>::print(BinarySearchTree<Comparable, Comparator>::TreeNode *root) const {

    if (root != NULL) {

        std::cout << root->element << " ";

        if (root->left != NULL) {
            print(root->left);
        }

        if (root->right != NULL) {
            print(root->right);
        }
    }
}

template<typename Comparable, typename Comparator>
void BinarySearchTree<Comparable, Comparator>::print() const {
    print(root);
    std::cout << std::endl;
}

template<typename Comparable, typename Comparator>
typename BinarySearchTree<Comparable, Comparator>::TreeNode *BinarySearchTree<Comparable, Comparator>::findMax(BinarySearchTree<Comparable, Comparator>::TreeNode *root) const {
    TreeNode *leaf = root;
    while (leaf != NULL && leaf->right != NULL) {
        leaf = leaf->right;
    }
    return leaf;
}

template<typename Comparable, typename Comparator>
const Comparable BinarySearchTree<Comparable, Comparator>::findMax() const {
    TreeNode *treeNode = findMax(root);
    return treeNode->element;
}

template<typename Comparable, typename Comparator>
typename BinarySearchTree<Comparable, Comparator>::TreeNode *BinarySearchTree<Comparable, Comparator>::findMin(BinarySearchTree<Comparable, Comparator>::TreeNode *root) const {
    TreeNode *leaf = root;
    while (leaf != NULL && leaf->left != NULL) {
        leaf = leaf->left;
    }
    return leaf;
}

template<typename Comparable, typename Comparator>
const Comparable BinarySearchTree<Comparable, Comparator>::findMin() const {
    TreeNode *treeNode = findMin(root);
    return treeNode->element;
}

template<typename Comparable, typename Comparator>
bool BinarySearchTree<Comparable, Comparator>::isEmpty() const {
    return root == NULL;
}

template<typename Comparable, typename Comparator>
bool BinarySearchTree<Comparable, Comparator>::isBalanced() const {
    return balanced;
}

template<typename Comparable, typename Comparator>
int BinarySearchTree<Comparable, Comparator>::getHeight() const {
    return height;
}

template<typename Comparable, typename Comparator>
const Comparable BinarySearchTree<Comparable, Comparator>::operator[](const Comparable *item) const {
    return get(item);
}

template<typename Comparable, typename Comparator>
const Comparable BinarySearchTree<Comparable, Comparator>::operator[](const Comparable item) const {
    return get(&item);
}

template<typename Comparable, typename Comparator>
const Comparable BinarySearchTree<Comparable, Comparator>::get(const Comparable *item) const {
    TreeNode *leaf = root;

    while (leaf != NULL && (leaf->left != NULL || leaf->right != NULL)) {
        if (*item == leaf->element) break;

        if (isLessThan(*item, leaf->element)) {
            leaf = leaf->left;
        }
        leaf = leaf->right;
    }


    return leaf->element;
}


template<typename Comparable, typename Comparator>
const Comparable BinarySearchTree<Comparable, Comparator>::get(const Comparable item) const {
    get(&item);
}

template<typename Comparable, typename Comparator>
void BinarySearchTree<Comparable, Comparator>::remove(const Comparable item) {
    remove(&item);
}

template<typename Comparable, typename Comparator>
void BinarySearchTree<Comparable, Comparator>::remove(const Comparable *item) {
    std::cout << "trying to remove the value of " << *item << std::endl;

    // if item doesn't exist in binary search tree
    if (!contains(item)) {
        std::cout << "item " << *item << " is not in the binary search tree" << std::endl;
        return;
    }

    TreeNode *current = root;
    TreeNode *parent = NULL;

    while (current && (current->left != NULL || current->right != NULL)) {
        if (*item == current->element) break;
        parent = current;
        if (isLessThan(*item, current->element)) {
            current = current->left;
            continue;
        }
        current = current->right;
    }

    if (parent == NULL) {
        remove(current->element);
    }

    if (isLeaf(current)) {
        std::cout << "deleting leaf node " << "\n";
        current = NULL;
        delete current;
    }

    // has left nodes no right nodes
    if (current->left != NULL && current->right == NULL) {
        std::cout << "has left nodes and no right nodes" << std::endl;
        if (parent->right == current) {
            parent->right == current->left;
        } else if (parent->left == current) {
            parent->left = current->left;
        }
        delete current;
    }

    // has right nodes and no left nodes
    if (current->right != NULL && current->left == NULL) {
        std::cout << "has right nodes no left nodes" << std::endl;
        if (parent->right == current) {
            parent->right == current->right;
        } else if (parent->left == current) {
            parent->left = current->right;
        }
        delete current;
    }

    // has both right nodes and no left nodes
    if (current->left != NULL && current->right != NULL) {

        TreeNode *min = findMin(current);
        std::cout << "has both left nodes and right nodes " << std::endl;

    }
}

