
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
void AvlTree<T>::insert(const T &value) {
    this->safe_insert(value);
}


template <class T>
void AvlTree<T>::traversal_in_order() {
    if (this->left != nullptr)
        this->left->traversal_in_order();
    cout << this->data << " ";
    if (this->right != nullptr)
        this->right->traversal_in_order();
}


template <class T>
void AvlTree<T>::update_height() {
    if (this->left != nullptr && this->right != nullptr)
        this->height = max(this->left->height, this->right->height) + 1;
    else if (this->left != nullptr)
        this->height = this->left->height + 1;
    else if (this->right != nullptr)
        this->height = max(this->left->height, this->right->height) + 1;
    else
        this->height = 1;
}


template <class T>
bool AvlTree<T>::is_balanced() {
    return !this->is_unbalanced();
}


template <class T>
bool AvlTree<T>::is_unbalanced() {
    if (this->left != nullptr && this->right != nullptr)
        return  (abs(this->left->height - this->right->height) <= 1);
    else if (this->left != nullptr)
        return (this->left->height <= 1);
    else if (this->right != nullptr) {
        return (this->right->height <= 1);
    }
    else
        return true;
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
queue<AvlTree<T>*> AvlTree<T>::safe_insert(const T &value) {
    queue<AvlTree<T>*> children;

    // Regular binary search tree insert
    if (value < this->data) {
        if (this->left != nullptr) {
            children = this->left->safe_insert(value);

            if (children.size() == 0) // A balancing already occurred and has been dealt with already
                return children;
            else if (children.size() == 1) { // A balancing already occurred and the queue contains the new root
                this->left = children.front(); // Update the new root
                this->update_height();
                return queue<AvlTree<T>*>();
            }
        }
        else {
            this->left = new AvlTree(value);
            children.push(nullptr);  // Grand child first (will never be used anyway)
            children.push(this->left);  // Then child
        }
    }
    else {
        if (this->right != nullptr) {
            children = this->right->safe_insert(value);

            if (children.size() == 0) // A balancing already occurred and has been dealt with already
                return children;
            else if (children.size() == 1) { // A balancing already occurred and the queue contains the new root
                this->right = children.front(); // Update the new root
                this->update_height();
                return queue<AvlTree<T>*>();
            }
        }
        else {
            this->right = new AvlTree(value);
            children.push(nullptr);  // Grand child first (will never be used anyway)
            children.push(this->right);  // Then child
        }
    }


    // If reached, no balancing has occurred, and we are looking for an unbalanced node
    if (this->is_balanced()) {
        children.pop();  // Remove grand child. Now the child is is the grand child
        children.push(this);  // Push new child

        return children;
    }
    else { // Unbalanced node found
        AvlTree<T>* old_root = this;
        AvlTree<T>* child = children.back();
        AvlTree<T>* grandchild = children.front();

        AvlTree<T>* new_root = nullptr;

        // Balance the tree
        if (old_root->left == child) { // Left case
            if (child->left == grandchild) // Left left case
                new_root = old_root->right_rotation();
            else { // Left right case
                new_root = child->left_rotation();
                old_root->left = new_root;
                new_root = old_root->right_rotation();
            }
        }
        else { // Right case
            if (child->right == grandchild) // Right right case
                new_root = old_root->left_rotation();
            else { // Right left case
                new_root = child->right_rotation();
                old_root->right = new_root;
                new_root = old_root->left_rotation();
            }
        }

        // Return the new root of this subtree
        children.push(new_root);
        return children;
    }
}



int main() {
    AvlTree<int>* tree = new AvlTree<int>;
    tree->insert(1);
    tree->insert(0);
    tree->insert(2);
    tree->insert(3);
    tree->insert(1);

    cout << "Traversal: " << endl;
    tree->traversal_in_order();
    cout << endl;


    return EXIT_SUCCESS;
}