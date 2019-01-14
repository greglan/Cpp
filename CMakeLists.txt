cmake_minimum_required (VERSION 2.6)
project (Progs)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(singly_linked_lists data_structures/lists/SinglyLinkedList.cpp)
add_executable(stacks data_structures/stacks/Stack.cpp)
add_executable(queues data_structures/queues/Queue.cpp)
add_executable(min_heaps data_structures/trees/heaps/MinHeap.cpp)
add_executable(binary_trees data_structures/trees/BinarySearchTree.cpp)
add_executable(avl_trees data_structures/trees/AvlTree.cpp)
add_executable(graph_searches data_structures/graphs/searches.cpp)

add_executable(unweighted_graphs data_structures/graphs/UnweightedGraph.cpp)
add_executable(unweighted_graphs_test data_structures/graphs/UnweightedGraph.cpp data_structures/graphs/UnweightedGraph_test.cpp)
target_include_directories(unweighted_graphs_test PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(unweighted_graphs_test ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})


add_executable(strings utils/strings.cpp)
