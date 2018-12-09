#ifndef PROGS_MINHEAP_H
#define PROGS_MINHEAP_H

#include <vector>
using namespace std;


template <class T>
class MinHeap {
private:
    vector<T> nodes;

    void percolate(int index);

public:
    void insert(T const& value);
    T get_min() const;
};


#endif //PROGS_MINHEAP_H
