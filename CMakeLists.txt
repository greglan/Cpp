cmake_minimum_required (VERSION 2.6)
project (Progs)

add_executable(singly_linked_lists data_structures/lists/SinglyLinkedList.cpp)
add_executable(stacks data_structures/stacks/Stack.cpp)
add_executable(queues data_structures/queues/Queue.cpp)
add_executable(min_heaps data_structures/trees/heaps/MinHeap.cpp)
add_executable(binary_trees data_structures/trees/BinaryTree.cpp)
add_executable(graph_searches data_structures/graphs/searches.cpp)
