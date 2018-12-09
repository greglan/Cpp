#include <iostream>
#include "Queue.h"

using namespace std;


bool Queue::empty() {
    return (this->head == nullptr);
}


void Queue::push(int data) {
    QueueNode* new_node = new QueueNode(data);

    if (this->tail != nullptr) {
        this->tail->next = new_node;
    }
    else {
        this->head = new_node;
    }

    this->tail = new_node;
}


int Queue::pop() {
    if (this->head != nullptr) {
        QueueNode* node = this->head;
        this->head = node->next;

        if (this->tail == node)
            this->tail = nullptr;

        int data = node->data;
        delete node;
        return data;
    }
    else
        throw QueueEmptyException();
}


int main() {
    Queue* queue = new Queue;

    cout << "Queue empty: " << queue->empty() << endl;
    cout << endl;

    queue->push(1);
    queue->push(2);
    queue->push(3);
    cout << "Queue empty: " << queue->empty() << endl;
    cout << "Queue pop: " << queue->pop() << endl;
    cout << "Queue pop: " << queue->pop() << endl;
    cout << "Queue pop: " << queue->pop() << endl;
    cout << endl;

    cout << "Queue empty: " << queue->empty() << endl;
    queue->pop();
}