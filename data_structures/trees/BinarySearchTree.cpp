#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "BinarySearchTree.h"

using namespace std;


/* Single Node methods */
template <class T>
Node<T>::Node(T const& data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

template <class T>
void Node<T>::insert(T const& value) {
    if (value < this->data)
    {
        if (this->left != nullptr)
            this->left->insert(value);
        else
            this->left = new Node<T>(value);
    }
    else {
        if (this->right != nullptr)
            this->right->insert(value);
        else
            this->right = new Node<T>(value);
    }
}


template <class T>
Node<T>* Node<T>::search(T const& value) {
    if (value < this->data)
    {
        if (this->left != nullptr)
            return this->left->search(value);
        else
            return nullptr;
    }
    else if (this->data < value){
        if (this->right != nullptr)
            return this->right->search(value);
        else
            return nullptr;
    }
    else if (this->data == data)
        return this;
    else
        return nullptr;
}


template <class T>
Node<T>* Node<T>::get_min_child() {
    Node<T>* parent = this;
    Node<T>* current = parent->left;

    while (current->left != nullptr){
        parent = current;
        current = current->left;
    }

    return parent;
}


template <class T>
void Node<T>::traversal_in_order() {
    if (this->left != nullptr)
        this->left->traversal_in_order();
    cout << this->data << " ";
    if (this->right != nullptr)
        this->right->traversal_in_order();
}


template <class T>
void Node<T>::traversal_post_order() {
    if (this->left != nullptr)
        this->left->traversal_post_order();
    if (this->right != nullptr)
        this->right->traversal_post_order();
    cout << this->data << " ";
}


template <class T>
void Node<T>::traversal_pre_order() {
    cout << this->data << " ";
    if (this->left != nullptr)
        this->left->traversal_pre_order();
    if (this->right != nullptr)
        this->right->traversal_pre_order();
}


template <class T>
long int Node<T>::is_balanced() {
    if (this->left == nullptr and this->right == nullptr)
        return 1;
    else if (this->left == nullptr) {
        if (this->right->is_leaf())
            return 2;
        else
            return -1; // Not balanced
    } else if (this->right == nullptr) {
        if (this->left->is_leaf())
            return 2;
        else
            return -1; // Not balanced
    } else {
        long int left_balance = this->left->is_balanced();
        long int right_balance = this->right->is_balanced();

        if (left_balance == -1 || right_balance == -1)
            return -1;
        else if (abs(left_balance-right_balance) <= 1)
            return 1 + max(left_balance, right_balance);
        else
            return -1;
    }
}


template <class T>
bool Node<T>::is_leaf() {
    return (this->left == nullptr && this->right == nullptr);
}



/* Binary tree wrapper methods */
template <class T>
BinarySearchTree<T>::BinarySearchTree() {
    this->root = nullptr;
}


template <class T>
BinarySearchTree<T>::BinarySearchTree(Node<T>* root) {
    this->root = root;
}

template <class T>
bool BinarySearchTree<T>::empty() {
    return (root == nullptr);
}

template <class T>
void BinarySearchTree<T>::insert(T const& value) {
    if (this->root != nullptr)
        this->root->insert(value);
    else
        this->root = new Node<T>(value);
}


template <class T>
Node<T>* BinarySearchTree<T>::search(T const& value) {
    if (this->root != nullptr)
        return this->root->search(value);
    else
        throw TreeEmptyException();
}


template <class T>
void BinarySearchTree<T>::remove(const T &value) {
    // First step is to find the node to delete
    Node<T>* parent = nullptr;
    Node<T>* to_delete = this->root;

    while (to_delete != nullptr && to_delete->data != value)
    {
        parent = to_delete;

        if (value < to_delete->data)
            to_delete = to_delete->left;
        else
            to_delete = to_delete->right;
    }

    // If not found, throw exception
    if (to_delete == nullptr)
        throw NotFoundException();

    // Else, to_delete is the node to delete
    // Node to delete is a leaf
    if (to_delete->left == nullptr && to_delete->right == nullptr){
        if (parent == nullptr)
            this->root = nullptr;
        else{
            if (parent->left == to_delete)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }
    }
    // Node to delete has no left child. Replace it with its right child
    else if (to_delete->left == nullptr){
        if (parent == nullptr) // Node to delete is the root
            this->root = to_delete->right;
        else{
            if (parent->left == to_delete)
                parent->left = to_delete->right;
            else
                parent->right = to_delete->right;
        }
    }
        // Node to delete has no right child. Replace it with its left child
    else if (to_delete->right == nullptr){
        if (parent == nullptr) // Node to delete is the root
            this->root = to_delete->right;
        else{
            if (parent->left == to_delete)
                parent->left = to_delete->left;
            else
                parent->right = to_delete->left;
        }
    }
    // Node to delete has two children
    else{
        // FIXME: add member to switch delete method (predecessor)
        Node<T>* predecessor_parent = to_delete->get_min_child();
        Node<T>* predecessor = predecessor_parent->left;

        if (to_delete->left != predecessor) // Prevent predecessor from pointing to itself
            predecessor->left = to_delete->left;
        predecessor->right = to_delete->right;
        predecessor_parent->left = nullptr;

        // Update parent of the node to delete
        if (parent != nullptr) // Node to delete is not the root
        {
            if (parent->left == to_delete)
                parent->left = predecessor;
            else
                parent->right = predecessor;
        }
        else
            this->root = predecessor;
    }

    delete to_delete;
}


template <class T>
void BinarySearchTree<T>::traversal_in_order() {
    this->root->traversal_in_order();
    cout << endl;
}


template <class T>
void BinarySearchTree<T>::traversal_post_order() {
    this->root->traversal_post_order();
    cout << endl;
}


template <class T>
void BinarySearchTree<T>::traversal_pre_order() {
    this->root->traversal_pre_order();
    cout << endl;
}


BinarySearchTree<int>* array_to_binary_tree(int* array, unsigned long size)
{
    // Sort the given array
    sort(array, array+size);

    BinarySearchTree<int>* tree = new BinarySearchTree<int>;
    // TODO
    return tree;
}


template <class T>
bool BinarySearchTree<T>::is_balanced() {
    return (this->root->is_balanced() != -1);
}


int main() {
    BinarySearchTree<int>* tree = new BinarySearchTree<int>;
    tree->insert(1);
    tree->insert(0);
    tree->insert(2);
    tree->insert(3);
    tree->insert(1);
    cout << "Tree balanced: " << tree->is_balanced() << endl;

    tree->search(0);
    tree->search(1);
    tree->search(2);
    tree->search(3);

    tree->remove(3);
    tree->insert(3);

    tree->remove(0);
    tree->insert(0);

    tree->remove(2);
    tree->remove(1);

    cout << "Traversals" << endl;
    tree->traversal_in_order();
    tree->traversal_post_order();
    tree->traversal_pre_order();
    cout << endl;

    cout << "Tree balanced: " << tree->is_balanced() << endl;

    return EXIT_SUCCESS;
}