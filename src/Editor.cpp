#include "../include/Editor.hpp"
#include "../include/LinkedList.hpp"
#include "../include/ListNode.hpp"
#include <iostream>
#include <cstdlib>

Editor::Editor(){
    this->list = new LinkedList();
    this->currentPage = 0;
    this->currentPageNode = this->list->getHead()->getNext();

}

size_t Editor::getCurrentPage() const{
    return this->currentPage;
}

LinkedList* Editor::getList() const{
    return this->list;
}

size_t Editor::getNumLines() const{
    return this->numLines;
}

ListNode* Editor::getCurrentPageNode() const{
    return this->currentPageNode;
}

void Editor::setCurrentPage(size_t val){
    this->currentPage = val;
}

void Editor::setNumLines(size_t val){
    this->numLines = val;
}

void Editor::incrementNumLines(){
    this->numLines++;
}

void Editor::decrementNumLines(){
    this->numLines--;
}

void Editor::appendLine(const std::string& line){
    ListNode *node = new ListNode(line);
    node->setNext(this->getList()->getTail());
    node->setPrev(this->getList()->getTail()->getPrev());
    this->getList()->getTail()->getPrev()->setNext(node);
    this->getList()->getTail()->setPrev(node);
    
    if (this->numLines == 0){
        this->currentPageNode = this->getList()->getHead()->getNext();
    }
    this->incrementNumLines();
}

void Editor::incrementCurrentPageNode(){
    ListNode* temp = this->currentPageNode;
    for (int i = 0; i < 10; i++)
        temp = temp->getNext();
    this->currentPageNode = temp;
}

void Editor::decrementCurrentPageNode(){
    ListNode* temp = this->currentPageNode;
    for (int i=0; i < 10; i++)
        temp = temp->getPrev();
    this->currentPageNode = temp;
}


void Editor::printCurrentPage() const{
    system("clear||cls");
    int i = 0;
    ListNode* temp = this->currentPageNode;
    while (i < 10 && temp != this->list->getTail()){
        std::cout << temp->getText() << '\n';
        i += 1;
        temp = temp->getNext();
    }
}


