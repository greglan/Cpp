#include <cstdlib>
#include <iostream>
#include "MinHeap.h"


template <class T>
MinHeap<T>::MinHeap() {
    T init;
    this->nodes.push_back(init);
}


template <class T>
void MinHeap<T>::add(const T &value) {
    this->nodes.push_back(value);
    unsigned long last_index = this->nodes.size()-1;
    this->percolate_up(last_index);
}


template <class T>
T MinHeap<T>::get() {
    unsigned long n = this->nodes.size();

    if (n <= 1)
        throw EmptyHeapException();

    T min_value = this->nodes.at(1);
    this->nodes[1] = this->nodes.at(this->nodes.size()-1);
    this->nodes.pop_back();
    this->percolate_down(1);
    return min_value;
}


template <class T>
void MinHeap<T>::percolate_up(unsigned long index) {
    unsigned long current = index;
    unsigned long parent = index / 2;

    while(parent > 0 && this->nodes.at(current) < this->nodes.at(parent))
    {
        this->swap(current, parent);
        current = parent;
        parent = current / 2;
    }
}


template <class T>
void MinHeap<T>::percolate_down(unsigned long index) {
    unsigned long n = this->nodes.size();
    unsigned long current = index;
    unsigned long child = this->get_min_child_index(current);

    while(child < n && this->nodes.at(current) > this->nodes.at(child))
    {
        this->swap(current, child);
        current = child;
        child = this->get_min_child_index(current);
    }
}


template <class T>
unsigned long MinHeap<T>::get_min_child_index(unsigned long index) {
    unsigned long size = this->nodes.size();
    unsigned long left_child = 2*index;
    unsigned long right_child = 2*index + 1;

    if (left_child > size)
        return index;

    if (right_child > size)
        return left_child;

    if (this->nodes[left_child] < this->nodes[right_child])
        return left_child;
    else
        return right_child;
}

template <class T>
void MinHeap<T>::swap(unsigned long i, unsigned long j) {
    T tmp = this->nodes.at(i);
    this->nodes.at(i) = this->nodes.at(j);
    this->nodes.at(j) = tmp;
}


int main(){
    MinHeap<int> heap;

    heap.add(1);
    heap.add(0);
    heap.add(2);

    std::cout << heap.get() << endl;
    std::cout << heap.get() << endl;
    std::cout << heap.get() << endl;

    heap.add(0);
    heap.add(1);
    heap.add(2);

    std::cout << heap.get() << endl;
    std::cout << heap.get() << endl;
    std::cout << heap.get() << endl;

    heap.add(2);
    heap.add(1);
    heap.add(0);

    std::cout << heap.get() << endl;
    std::cout << heap.get() << endl;
    std::cout << heap.get() << endl;

    cout << endl;
    heap.add(1);
    heap.add(0);
    heap.add(2);
    heap.add(3);
    heap.add(4);
    heap.add(-1);

    std::cout << heap.get() << endl;
    std::cout << heap.get() << endl;
    std::cout << heap.get() << endl;
    std::cout << heap.get() << endl;
    std::cout << heap.get() << endl;
    std::cout << heap.get() << endl;
    return EXIT_SUCCESS;
}