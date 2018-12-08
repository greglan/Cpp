#include <cstdlib>
#include "LinkedList.h"


LinkedList::LinkedList()
{
    this->next = nullptr;
}


LinkedList::LinkedList(int data)
{
    this->data = data;
    this->next = nullptr;
}


LinkedList::~LinkedList()
{
    if (this->next != nullptr)
        delete this->next;
}


void LinkedList::add(int data)
{
    if (this->next != nullptr)
        this->next->add(data);
    else
        this->next = new LinkedList(data);
}


void LinkedList::remove(int data)
{
    if (this->data == data && this->next == nullptr)
        delete this;
    else
    {
        LinkedList* current_node = this;
        LinkedList* next_node = current_node->next;  // This can't be nullptr because of the previous if statement

        // Search the node to delete
        while (next_node->data != data)
        {
            current_node = next_node;
            next_node = next_node->next;

            if (next_node == nullptr) // End of list: the data wasn't found. Just return
                return;
        }

        // From here, the node to delete is next_node, and its parent is current_node
        current_node->next = next_node->next;
        delete next_node;

    }
}


void LinkedList::print()
{
    //TODO
}


int main()
{
    LinkedList *list;
    LinkedList *list_2;

    list = new LinkedList();
    list->add(2);
    list->add(2);
    list->add(5);
    delete list;

    list = new LinkedList(2);
    list->add(2);
    list->add(1);
    delete list;

    list = new LinkedList(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->remove(1);
    list->remove(3);
    list->remove(4);
    list->remove(2);
    delete list;

    /*
    list = new LinkedList(0);
    list.add(1);
    list.add(2);
    list.add(3);
    list.remove_by_index(0);
    list.remove_by_index(2);
    list.remove_by_index(3);
    list.remove_by_index(1);
    delete list;
     */

    return EXIT_SUCCESS;
}