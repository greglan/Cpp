#include <cstdlib>
#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;


SinglyLinkedList::SinglyLinkedList(int data)
{
    this->head = new SinglyLinkedListNode(data);
    this->tail = this->head;
}


SinglyLinkedList::~SinglyLinkedList()
{
    SinglyLinkedListNode* current_node = this->head;
    SinglyLinkedListNode* next_node;

    while (current_node != nullptr){
        next_node = current_node->next;
        delete current_node;
        current_node = next_node;
    }
}


bool SinglyLinkedList::empty() {
    return (this->tail == nullptr);
}


void SinglyLinkedList::append(int data)
{
    if (!this->empty()){
        this->tail->next = new SinglyLinkedListNode(data); // Add node at the end
        this->tail = this->tail->next;
    }
    else { // This is an empty list
        this->head = new SinglyLinkedListNode(data);
        this->tail = this->head;
    }
}


void SinglyLinkedList::remove(int data)
{
    if (this->empty())
        throw ListEmptyException();
    else if (this->head->data == data) { // The head is the node to delete
        SinglyLinkedListNode* to_delete = this->head;
        this->head = to_delete->next;
        if (this->tail == to_delete)
            this->tail = nullptr;
        delete to_delete;
    }
    else { // We can assume the head is not the node to delete
        SinglyLinkedListNode* parent_node = this->head;
        SinglyLinkedListNode* current_node = parent_node->next;

        // Search the node to delete
        while (current_node != nullptr && current_node->data != data) {
            parent_node = current_node;
            current_node = current_node->next;
        }

        if (current_node == nullptr) // Data not found
            throw NotFoundException();

        // From here, the node to delete is current_node
        parent_node->next = current_node->next;
        if (this->tail == current_node)
            this->tail = parent_node;
        delete current_node;
    }
}


void SinglyLinkedList::print()
{
    cout << "[";

    if (!this->empty()) {
        //TODO
        cout << this->head->data;
        SinglyLinkedListNode* node = this->head->next;

        while (node != nullptr)
        {
            cout << " -> " << node->data;
            node = node->next;
        }
    }

    cout << "]" << endl;
}


int main()
{
    SinglyLinkedList *list;

    list = new SinglyLinkedList(2);
    list->append(2);
    list->append(1);
    delete list;

    list = new SinglyLinkedList(1);
    list->append(2);
    list->append(3);
    list->append(4);
    list->print();
    list->remove(1);
    list->print();
    list->remove(3);
    list->print();
    list->remove(4);
    list->print();
    list->remove(2);
    list->print();
    delete list;

    /*
    list = new SinglyLinkedList(0);
    list.add(1);
    list.add(2);
    list.append(3);
    list.remove_by_index(0);
    list.remove_by_index(2);
    list.remove_by_index(3);
    list.remove_by_index(1);
    delete list;
     */

    return EXIT_SUCCESS;
}