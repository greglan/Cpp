#ifndef PROGS_BINARYTREE_H
#define PROGS_BINARYTREE_H

#include <exception>


template <class T>
class Node{
public:
    T data;
    Node* left;
    Node* right;

    Node<T>(T const& data);
    void insert(T const& value);
    Node<T>* search(T const& value);
    Node<T>* get_min_parent();
};


template <class T>
class BinaryTree {
public:
    Node<T>* root;

    BinaryTree();
    void insert(T const& value);
    Node<T>* search(T const& value);
    void remove(T const& value);
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
#endif //PROGS_BINARYTREE_H
