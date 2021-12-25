#include "../include/ListNode.hpp"

ListNode::ListNode(const std::string& text){
    this->text = text;
}
ListNode* ListNode::getNext() const{
    return this->next;
}
ListNode* ListNode::getPrev() const{
    return this->prev;
}
std::string ListNode::getText() const{
    return this->text;
}
void ListNode::setNext(ListNode* next){
    this->next = next;
}
void ListNode::setPrev(ListNode *prev){
    this->prev = prev;
}

void ListNode::setText(const std::string& text){
    this->text = text;
}