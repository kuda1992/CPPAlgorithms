#include "iostream"
#include "vector"
#include "algorithm"
#include "stack"

#if  defined(__unix__) || defined(__APPLE__)

#include "sys/resource.h"

#endif

/**
 * Binary tree traversals.
 * <p>
 * Remember when to push node into the stack
 * and when to pop node out of the stack.
 */
class TreeOrders {

private:
    int n = 0;
    std::vector<int> key;
    std::vector<int> left;
    std::vector<int> right;

    /**
     * Push all nodes on the path root -> left most into stack
     */
    void push_all(std::stack<int> &stack, int root) {

        while (root != -1) {
            stack.push(root);
            root = left[root];
        }
    }


public:
    void read() {

        std::cin >> n;

        key.resize(n);
        left.resize(n);
        right.resize(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> key[i] >> left[i] >> right[i];
        }
    }


    /**
     * Key idea
     * Start at the root
     *
     * Push all nodes 'along the path' from root to left most - into stack
     * while stack is not empty, print top
     * push all nodes along the path from its right- subtree to  left-most
     * @return
     */
    std::vector<int> in_order() {

        std::vector<int> results;
        std::stack<int> stack;

        push_all(stack, 0);

        while (!stack.empty()) {

            int top = stack.top();
            stack.pop();

            results.push_back(key[top]);
            top = right[top];
            push_all(stack, top);
        }


        return results;
    }


    /**
     * Key idea
     * Push into stack
     * While stack is not empty, pop and print top
     * Push its non-null right, left child into stack
     * @return
     */
    std::vector<int> pre_order() {

        std::vector<int> results;
        std::stack<int> stack;

        stack.push(0);

        while (!stack.empty()) {

            int top = stack.top();
            stack.pop();

            results.push_back(key[top]);

            if (right[top] != -1) stack.push(right[top]);
            if (left[top] != -1) stack.push(left[top]);

        }

        return results;
    }


    /**
     * Key idea:
     *
     * Almost like preorder
     * Given the output of post order, what is from right to left?
     * Push the root and while stack is not empty , pop top
     * Insert top at the head
     * Push its non-null left, right child and stack.
     * @return
     */
    std::vector<int> post_order() {

        std::vector<int> results;
        std::stack<int> stack;

        stack.push(0);

        while (!stack.empty()) {

            int top = stack.top();
            stack.pop();

            results.emplace(results.begin(), key[top]);

            if (left[top] != -1) stack.push(left[top]);
            if (right[top] != -1) stack.push(right[top]);

        }

        return results;
    }

};


void print(std::vector<int> a) {

    for (int i = 0; i < a.size(); ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << a[i];

    }
    std::cout << '\n';
}


int main_with_large_stack_space() {

    std::ios_base::sync_with_stdio(false);

    TreeOrders treeOrders;

    treeOrders.read();

    print(treeOrders.in_order());
    print(treeOrders.pre_order());
    print(treeOrders.post_order());
    return 0;
}

/*
int main(int argc, char **argv) {

#if defined(__unix__) || defined(__APPLE__)

    // allow larger stack space

    const rlim_t kStackSize = 16 * 1024 * 1024; // min stack size = 16MB

    struct rlimit rlimit{};

    int result;

    result = getrlimit(RLIMIT_STACK, &rlimit);

    if (result == 0) {

        if (kStackSize > rlimit.rlim_cur) {
            result = setrlimit(RLIMIT_STACK, &rlimit);

            if (result != 0) {
                std::cerr << "setrlimit returned result = " << result << std::endl;
            }
        }
    }

#endif


    return main_with_large_stack_space();
}*/
