#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListNode.hpp"

class LinkedList{
    private:
        ListNode *dummy_head = nullptr;
        ListNode *dummy_tail = nullptr;
    public:
        LinkedList();
        ~LinkedList();
        ListNode* getHead() const;
        ListNode* getTail() const;

};
#endif