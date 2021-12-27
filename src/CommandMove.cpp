#include "../include/CommandMove.hpp"
#include "../include/CommandDelete.hpp"
#include "../include/CommandInsert.hpp"
#include "../include/CommandReplace.hpp"

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
    temp->setText("");
    if (this->m > editor->getNumLines()){
        Command *insertCommand = new CommandInsert(this->m, movedText);
        insertCommand->apply(editor);
    }else{
        Command* replaceCommand = new CommandReplace(this->m, movedText);
        replaceCommand->apply(editor);
    }

    
}

void CommandMove::reverseApply(Editor* editor){

}