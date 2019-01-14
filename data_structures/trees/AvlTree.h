#ifndef PROGS_AVLTREE_H
#define PROGS_AVLTREE_H


template <class T>
class AvlTreeNode {
public:

};


template <class T>
class AvlTree {
public:
    T data;
    AvlTree<T>* left;
    AvlTree<T>* right;
    long height;

    AvlTree();
    AvlTree(T const& value);
    AvlTree<T>* left_rotation();
    AvlTree<T>* right_rotation();
    void insert(T const& value);
    void remove(T const& value);

private:
    AvlTree<T>* bst_insert(T const& value);
};


#endif //PROGS_AVLTREE_H
