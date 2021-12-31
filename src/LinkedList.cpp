#include "../include/LinkedList.hpp"
#include "../include/ListNode.hpp"

LinkedList::LinkedList()
{
    this->dummy_head = new ListNode("");
    this->dummy_tail = new ListNode("");

    // initially, the head and tail are the only nodes,
    // and they are connected to each other.
    this->dummy_head->setNext(this->dummy_tail);
    this->dummy_tail->setPrev(this->dummy_head);
}

ListNode *LinkedList::getHead() const
{
    return this->dummy_head;
}

ListNode *LinkedList::getTail() const
{
    return this->dummy_tail;
}

// when the linked list is destructed
// the memory allocated for each node of the list should be deallocated.
LinkedList::~LinkedList()
{
    ListNode *temp = dummy_head;
    while (temp)
    {
        ListNode *saved = temp->getNext();
        delete temp;
        temp = saved;
    }
}
