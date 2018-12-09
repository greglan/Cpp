#ifndef PROGS_LINKED_LISTS_H
#define PROGS_LINKED_LISTS_H

#include <exception>


class SinglyLinkedList {
    class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode* next;

        SinglyLinkedListNode(int data) {
            this->data = data;
            this->next = nullptr;
        }

    };

public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList(int data);
    ~SinglyLinkedList();
    bool empty();
    void append(int data);
    void remove(int data);
    void print();
    //int remove_by_index(int index);

};

struct ListEmptyException : public std::exception {
    const char * what () const throw () {
        return "Empty list";
    }
};

struct NotFoundException : public std::exception {
    const char * what () const throw () {
        return "Data not found";
    }
};
#endif //PROGS_LINKED_LISTS_H
