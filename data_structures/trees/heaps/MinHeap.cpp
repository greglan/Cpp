#include "MinHeap.h"


template <class T>
void MinHeap<T>::insert(const T &value) {
    this->nodes.push_back(value);

}