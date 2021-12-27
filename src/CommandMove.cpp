#include "../include/CommandMove.hpp"
#include "../include/CommandDelete.hpp"
#include "../include/CommandInsert.hpp"

CommandMove::CommandMove(size_t n, size_t m){
    this->n = n;
    this->m = m;
}



void CommandMove::apply(Editor* editor){
    size_t i = editor->getCurrentPage() * 10 + 1;
    ListNode* temp = editor->getCurrentPageNode();
    while (i < this->n){
        i += 1;
        temp = temp->getNext();
    }
    while (i > this->n){
        i -= 1;
        temp = temp->getPrev();
    }
    
    std::string movedText = temp->getText();
    Command *deleteCommand = new CommandDelete(this->n);
    Command *insertCommand = new CommandInsert(this->m, movedText);
    deleteCommand->apply(editor);
    insertCommand->apply(editor);
}

void CommandMove::reverseApply(Editor* editor){

}