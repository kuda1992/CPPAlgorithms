cmake_minimum_required(VERSION 3.14)
project(Algorithms)

set(CMAKE_CXX_STANDARD 14)


add_executable(
        Algorithms

        main.cpp

        Fundamentals/host.cpp
        Fundamentals/getline.cpp
        Fundamentals/airport.cpp
        Fundamentals/pointers.cpp

        AlgorithmicToolBox/AlgorithmicWarmup/lcm.cpp
        AlgorithmicToolBox/GreedyAlgorithms/change.cpp
        AlgorithmicToolBox/DivideAndConquer/sorting.cpp
        AlgorithmicToolBox/AlgorithmicWarmup/gcd_naive.cpp
        AlgorithmicToolBox/DivideAndConquer/binary_search.cpp
        AlgorithmicToolBox/DivideAndConquer/sorting_example.cpp
        AlgorithmicToolBox/DynamicProgramming1/edit-distance.cpp
        AlgorithmicToolBox/DivideAndConquer/majority_element.cpp
        AlgorithmicToolBox/GreedyAlgorithms/covering_segments.cpp
        AlgorithmicToolBox/GreedyAlgorithms/factional_knapsack.cpp
        AlgorithmicToolBox/DynamicProgramming1/edit-distance-naive.cpp
        AlgorithmicToolBox/AlgorithmicWarmup/get_fibonacci_last_digit_naive.cpp


        DataStructures/hash_tables/phone_book.cpp
        DataStructures/stack.cpp Fundamentals/practise.cpp
        DataStructures/basic-data-structures/tree-height.cpp
        DataStructures/basic-data-structures/check_brackets.cpp
        DataStructures/basic-data-structures/process-packages.cpp
        DataStructures/priority-queues-and-disjoint-sets/job_queue.cpp
        DataStructures/priority-queues-and-disjoint-sets/build_heap.cpp
        DataStructures/hash_tables/hash_chains.cpp

        techiedelight/map.cpp
        techiedelight/tree.cpp
        techiedelight/peak_finder.cpp
        techiedelight/single-list.cpp
        techiedelight/PriorityQueue.cpp
        techiedelight/sort-binary-array-linear-time.cpp
        techiedelight/find-pair-with-given-sum-array.cpp
        techiedelight/in-place-merge-two-sorted-arrays.cpp
        techiedelight/group-elements-array-based-first-occurrence.cpp
        Fundamentals/AVLTree.cpp DataStructures/tree_traversals/tree-orders.cpp DataStructures/tree_traversals/BinarySearchTree.cpp DataStructures/tree_traversals/BinarySearchTree.h DataStructures/tree_traversals/trees_test.cpp DataStructures/priority-queues-and-disjoint-sets/union_find.cpp DataStructures/priority-queues-and-disjoint-sets/UnionFindClient.cpp DataStructures/basic-data-structures/LinkedList.cpp DataStructures/basic-data-structures/LinkedListTest.cpp DataStructures/basic-data-structures/Stack.cpp DataStructures/basic-data-structures/StackTest.cpp)