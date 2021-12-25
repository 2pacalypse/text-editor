#ifndef LISTNODE_H
#define LISTNODE_H
#include <string>
class ListNode{
    private:
        ListNode *next = nullptr;
        ListNode *prev = nullptr;
        std::string text;
    public:
        ListNode(const std::string& text);
        ListNode *getNext() const;
        ListNode *getPrev() const;
        std::string getText() const;

        void setNext(ListNode* next);
        void setPrev(ListNode* prev);
        void setText(const std::string& text);


};
#endif