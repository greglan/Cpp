#include "AvlTree.h"


template <class T>
AvlTree<T>::AvlTree() {
    this->left = nullptr;
    this->right = nullptr;
    this->height = 0;
}


template <class T>
AvlTree<T>::AvlTree(T const& value) {
    this->data = value;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}


template <class T>
AvlTree<T>* AvlTree<T>::left_rotation() {
    AvlTree<T>* x = this;
    AvlTree<T>* y = x->right;

    // Perform left rotation
    x->right = y->left;
    y->left = x;

    // Update heights
    y->height = max(y->left->height, y->right->height) + 1;
    x->height = max(x->left->height, x->right->height) + 1;

    return x;
}


template <class T>
AvlTree<T>* AvlTree<T>::right_rotation() {
    AvlTree<T>* y = this;
    AvlTree<T>* x = y->left;

    // Perform right rotation
    y->left = x->right;
    x->right = y;

    // Update heights
    y->height = max(y->left->height, y->right->height) + 1;
    x->height = max(x->left->height, x->right->height) + 1;

    return x;
}


template <class T>
void AvlTree<T>::insert(const T &value) {
    AvlTree<T>* inserted_node = bst_insert(value);
    // TODO
}


template <class T>
AvlTree<T>* AvlTree<T>::bst_insert(const T &value) {
    AvlTree<T>* new_node = nullptr;

    if (value < this->data) {
        if (this->left != nullptr)
            new_node = this->left->insert(value);
        else {
            this->left = AvlTree(value);
            new_node = this->left;
        }

        // Update height
        if (this->right != nullptr)
            this->height = max(this->left->height, this->right->height) + 1;
        else
            this->height = this->left->height + 1;
    }
    else {
        if (this->right != nullptr)
            new_node = this->right->insert(value);
        else {
            this->right = AvlTree(value);
            new_node = this->right;
        }

        // Update height
        if (this->left != nullptr)
            this->height = max(this->left->height, this->right->height) + 1;
        else
            this->height = this->right->height + 1;
    }

    return new_node;
}