#ifndef PROGS_STACK_H
#define PROGS_STACK_H

#include <exception>


class Stack {

private:
    class StackNode {
    public:
        int data;
        StackNode* previous_node;
    };

    StackNode* top;

public:
    bool empty();
    void push(int data);
    int pop();
};


struct StackEmptyException : public std::exception {
    const char * what () const throw () {
        return "Empty stack";
    }
};
#endif //PROGS_STACK_H
