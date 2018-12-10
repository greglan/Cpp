#include <cstdlib>
#include "BinaryTree.h"


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





/* Binary tree wrapper methods */
template <class T>
BinaryTree<T>::BinaryTree() {
    this->root = nullptr;
}


template <class T>
void BinaryTree<T>::insert(T const& value) {
    if (this->root != nullptr)
        this->root->insert(value);
    else
        this->root = new Node<T>(value);
}


template <class T>
Node<T>* BinaryTree<T>::search(T const& value) {
    if (this->root != nullptr)
        return this->root->search(value);
    else
        throw TreeEmptyException();
}


template <class T>
void BinaryTree<T>::remove(const T &value) {
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



int main() {
    BinaryTree<int>* tree = new BinaryTree<int>;
    tree->insert(1);
    tree->insert(0);
    tree->insert(2);
    tree->insert(3);
    tree->insert(1);

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

    return EXIT_SUCCESS;
}