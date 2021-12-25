#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListNode.hpp"

class LinkedList{
    private:
        ListNode *dummy_head = nullptr;
        ListNode *dummy_tail = nullptr;
        size_t numNodes = 0;
    public:
        LinkedList();
        ListNode* getHead() const;
        ListNode* getTail() const;
        void append(ListNode* node);
        //void insertAt(size_t index, ListNode* node);

};
#endif