#include "../include/LinkedList.hpp"
#include "../include/ListNode.hpp"
LinkedList::LinkedList(){
    this->dummy_head = new ListNode("");
    this->dummy_tail = new ListNode("");
    this->dummy_head->setNext(this->dummy_tail);
    this->dummy_tail->setPrev(this->dummy_head);

}

ListNode* LinkedList::getHead() const{
    return this->dummy_head;
}

ListNode* LinkedList::getTail() const{
    return this->dummy_tail;
}

