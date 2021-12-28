#include "../include/CommandReplace.hpp"
#include "../include/ListNode.hpp"

CommandReplace::CommandReplace(size_t n, const std::string& text){
    this->n = n;
    this->text = text;
}

void CommandReplace::apply(Editor& editor){
    if (this->n >= 1 && this->n <= editor.getNumLines()){

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
        temp->setText(this->text);
    }else{
        throw "Argument out of bounds.";
    }
}

void CommandReplace::reverseApply(Editor& editor){

}