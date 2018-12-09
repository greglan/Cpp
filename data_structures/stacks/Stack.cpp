#include <iostream>
#include "Stack.h"


using namespace std;


bool Stack::empty() {
    return (this->top == nullptr);
}


void Stack::push(int data) {
    StackNode* top = new StackNode();
    top->data = data;
    top->previous_node = this->top;
    this->top = top;
}


int Stack::pop() {
    if (this->top != nullptr){
        int data = this->top->data;
        this->top = this->top->previous_node;
        return data;
    }
    else {
        throw StackEmptyException();
    }
}


int main(){
    Stack* stack = new Stack();
    cout << "Stack empty: " << stack->empty() << endl;

    stack->push(1);
    cout << "Stack empty: " << stack->empty() << endl;

    cout << "Stack pop: " << stack->pop() << endl;
    cout << "Stack empty: " << stack->empty() << endl;

    stack->push(1);
    stack->push(2);
    cout << "Stack pop: " << stack->pop() << endl;
    cout << "Stack pop: " << stack->pop() << endl;

    stack->pop();
}