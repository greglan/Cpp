#ifndef PROGS_LINKED_LISTS_H
#define PROGS_LINKED_LISTS_H


class LinkedList {
public:
    int data;
    LinkedList* next;

    LinkedList(int data);
    ~LinkedList();
    void add(int data);
    void remove(int data);
    void print();
    //int remove_by_index(int index);

};


#endif //PROGS_LINKED_LISTS_H
