#ifndef PROGS_QUEUE_H
#define PROGS_QUEUE_H

#include <exception>

class Queue {
    class QueueNode{
    public:
        int data;
        QueueNode* next;

        QueueNode(int data){
            this->data = data;
        }
    };

    QueueNode* head;
    QueueNode* tail;

public:
    bool empty();
    void push(int data);
    int pop();

};


struct QueueEmptyException : public std::exception {
    const char * what () const throw () {
        return "Empty queue";
    }
};

#endif //PROGS_QUEUE_H
