#ifndef PROGS_STACK_H
#define PROGS_STACK_H


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


#endif //PROGS_STACK_H
