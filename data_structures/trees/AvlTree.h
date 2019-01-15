#ifndef PROGS_AVLTREE_H
#define PROGS_AVLTREE_H

#include <cstdlib>
#include <iostream>
#include <queue>


using namespace std;


template <class T>
class AvlTree {
private:
    T data;
    AvlTree<T>* left;
    AvlTree<T>* right;
    long height;

    void update_height();
    bool is_balanced();
    bool is_unbalanced();
    AvlTree<T>* left_rotation();
    AvlTree<T>* right_rotation();
    queue<AvlTree<T>*>safe_insert(T const& value);

public:
    AvlTree();
    AvlTree(T const& value);

    void insert(T const& value);
    void remove(T const& value);
    void traversal_in_order();
};


#endif //PROGS_AVLTREE_H
