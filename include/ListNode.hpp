#ifndef LISTNODE_H
#define LISTNODE_H
#include <string>
class ListNode{
    private:
        //doubly linked list nodes have connection to both the previous and the next neighbors.
        ListNode *next = nullptr;
        ListNode *prev = nullptr;
        //each node also holds a string associated with a line.
        std::string text;
    public:
        //constructor with the string argument
        ListNode(const std::string& text);

        //getters
        ListNode *getNext() const;
        ListNode *getPrev() const;
        std::string getText() const;

        //setters
        void setNext(ListNode* next);
        void setPrev(ListNode* prev);
        void setText(const std::string& text);


};
#endif