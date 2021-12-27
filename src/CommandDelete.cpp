#include "../include/CommandDelete.hpp"
#include "../include/ListNode.hpp"
#include "../include/CommandInsert.hpp"

CommandDelete::CommandDelete(size_t n){
    this->n = n;

}
void CommandDelete::apply(Editor& editor){
    if (editor.getNumLines() > 0){
        size_t i = editor.getCurrentPage() * 10 + 1;
        ListNode* temp = editor.getCurrentPageNode();
        while (i < this->n){
            i += 1;
            temp = temp->getNext();
        }
        while (i > this->n){
            i -= 1;
            temp = temp->getPrev();
        }

        this->deletedText = temp->getText();

        if (temp == editor.getCurrentPageNode()){
            editor.setCurrentPageNode(temp->getNext());
        }
        if (temp != editor.getList()->getHead() && temp != editor.getList()->getTail()){
            temp->getPrev()->setNext(temp->getNext());
            temp->getNext()->setPrev(temp->getPrev());
        }
        editor.decrementNumLines();
    }
}

void CommandDelete::reverseApply(Editor& editor){
    Command* reverseCommand = new CommandInsert(this->n, this->deletedText);
    reverseCommand->apply(editor);
}