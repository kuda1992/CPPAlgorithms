#include "iostream"
#include "vector"
#include "queue"
#include "climits"

template<typename T>
struct compare {
    bool operator()(const T &a, const T &b) {
        return a < b;
    }
};

template<typename T>
struct Node {
    T key;
    Node<T> *parent;
    Node<T> *left;
    Node<T> *right;
    int height;
};


template<typename T>
class AVLTree {

private:
    Node<T> *root;

    T min;
    T max;

    struct compare {

        bool operator()(const T &a, const T &b) {
            return a > b;
        }
    };

    Node<T> *insert(Node<T> *root, Node<T> *node) {

        if (root == nullptr) {
            return node;
        }

        if (node->key < root->key) {
            root->left = insert(root->left, node);
        } else if (node->key > root->key) {
            root->right = insert(root->right, node);
        }
        return root;
    }


    bool remove(T &key, Node<T> *&root) {
        // key not found;
        bool deleted = false;
        if (root == nullptr) {
            return deleted;
        }

        if (key == root->key) {
            deleted = true;
            if (root->right != nullptr) {
                *root = *root->right;
                return deleted;
            }
            if (root->left != nullptr) {
                *root = *root->left;
                return deleted;
            }

            root = nullptr;
            return deleted;
        } else if (key < root->key) {
            deleted = remove(key, root->left);
        } else if (key > root->key) {
            deleted = remove(key, root->right);
        }

        return deleted;
    }

    Node<T> *find(const T &key, const Node<T> *root) {

        //  std::cout << "the key is " << key << "\n";
        if (root && key == root->key) {
            return root;
        }

        if (root && key < root->key) {
            return find(key, root->left);
        }

        if (root && key > root->key) {
            return find(key, root->right);
        }
    }

    void re_balance(Node<T> *node) {

        Node<T> p = node->parent;

        if (node->left->height - node->right->height <= 1) return;

        if (node->left->height > node->right->height + 1) re_balance_right(node);

        if (node->right->height > node->left->height + 1) re_balance_left(node);


        adjust_height(node);

        if (p != nullptr) {
            re_balance(p);
        }
    }

    void re_balance_right(Node<T> *node) {}

    void re_balance_left(Node<T> *node) {}

    void adjust_height(Node<T> *node) {


    }


    void print(Node<T> *root) {

        if (root == nullptr) {
            return;
        }
        std::cout << root->key << " ";

        if (root->left) {
            print(root->left);
        }

        if (root->right) {
            print(root->right);
        }
    }

    void print_inorder(Node<T> *root, std::priority_queue<T, std::vector<T>, compare> *queue) {

        if (root == nullptr) {
            return;
        }

        queue->push(root->key);

        if (root->left) {
            print_inorder(root->left, queue);
        }

        if (root->right) {
            print_inorder(root->right, queue);
        }

    }


public:

    AVLTree() {
        root = nullptr;
    }

    void insert(T key) {

        Node<T> *node = new Node<T>;
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
        node->parent = root;

        root = insert(root, node); // insert the key into the tree
        // Node<T> node1 = find(key, &(root)); // find the key
        // re_balance(node1);
    }

    void print() {
        print(root);
    }

    bool remove(T key) {
        return remove(key, root);
    }


    void print_inorder() {
        std::priority_queue<T, std::vector<T>, compare> queue;
        print_inorder(root, &queue);

        while (!queue.empty()) {
            std::cout << queue.top() << " ";
            queue.pop();
        }

        std::cout << "\n";
    }

    T get(const T key) {
        return find(key, root)->key;
    }

    T operator[](const T key) {
        return get(key);
    }

};


/*
int main() {

    AVLTree<int> tree;

    int keys[] = {15, 10, 20, 8, 12, 16};


    for (int key: keys)
        tree.insert(key);


    tree.print_inorder();


    std::cout << "the cout " << INT_MIN << std::endl;
    std::cout << "the cout " << INT_MAX << std::endl;





    // std::cout << tree[2] << "\n";

}*/
