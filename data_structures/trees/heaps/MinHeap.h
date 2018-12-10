#ifndef PROGS_MINHEAP_H
#define PROGS_MINHEAP_H

#include <vector>
#include <exception>
using namespace std;


template <class T>
class MinHeap {
private:
    vector<T> nodes;

    void percolate_up(unsigned long index);
    void percolate_down(unsigned long index);
    unsigned long get_min_child_index(unsigned long index);
    void swap(unsigned long i, unsigned long j);

public:
    MinHeap();
    void add(T const &value);
    T get();
};


struct EmptyHeapException : public std::exception {
    const char * what () const throw () {
        return "Empty heap";
    }
};
#endif //PROGS_MINHEAP_H
