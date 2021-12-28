#include "../include/CommandMove.hpp"
#include "../include/CommandDelete.hpp"
#include "../include/CommandInsert.hpp"

CommandMove::CommandMove(size_t n, size_t m){
    this->n = n;
    this->m = m;
}

CommandMove::~CommandMove(){
    delete this->subcommand1;
    delete this->subcommand2;
}



void CommandMove::apply(Editor& editor){
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
    
    std::string movedText = temp->getText();
    subcommand1 = new CommandDelete(this->n);
    subcommand2 = new CommandInsert(this->m, movedText);
    subcommand1->apply(editor);
    subcommand2->apply(editor);
}

void CommandMove::reverseApply(Editor& editor){
    subcommand2->reverseApply(editor);
    subcommand1->reverseApply(editor);
}