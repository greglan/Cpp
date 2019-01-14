#ifndef PROGS_BINARYTREE_H
#define PROGS_BINARYTREE_H

#include <exception>
#include <list>
#include <vector>

using namespace std;

template <class T>
class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode<T>(T const& data);
    void insert(T const& value);
    BinaryTreeNode<T>* search(T const& value);
    BinaryTreeNode<T>* get_min_child();
    void traversal_in_order();
    void traversal_post_order();
    void traversal_pre_order();
    long int is_balanced();
    bool is_leaf();
};


template <class T>
class BinarySearchTree {
public:
    BinaryTreeNode<T>* root;

    BinarySearchTree();
    BinarySearchTree(BinaryTreeNode<T>* root);
    bool empty();
    void insert(T const& value);
    BinaryTreeNode<T>* search(T const& value);
    void remove(T const& value);
    void traversal_in_order();
    void traversal_post_order();
    void traversal_pre_order();
    vector<list<T>> list_of_depths();  // TODO
    bool is_balanced();
};


struct TreeEmptyException : public std::exception {
    const char * what () const throw () {
        return "Empty tree";
    }
};


struct NotFoundException : public std::exception {
    const char * what () const throw () {
        return "Value not found";
    }
};


BinarySearchTree<int>* array_to_binary_tree(int* array, unsigned long size);
#endif //PROGS_BINARYTREE_H
