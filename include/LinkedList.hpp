#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListNode.hpp"

class LinkedList{
    private:
        // doubly linked list with a dummy head and tail.
        // the lines are then in between the dummy nodes.
        ListNode *dummy_head = nullptr;
        ListNode *dummy_tail = nullptr;
    public:
        //constructor
        LinkedList();

        //destructor
        ~LinkedList();

        //getters
        ListNode* getHead() const;
        ListNode* getTail() const;

};
#endif