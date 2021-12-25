#include "../include/CommandReplace.hpp"
#include "../include/ListNode.hpp"

CommandReplace::CommandReplace(size_t n, const std::string& text){
    this->n = n;
    this->text = text;
}

void CommandReplace::apply(Editor* editor){
    if (editor->getCurrentPage() * 10 + this->n - 1 < editor->getNumLines()){
        ListNode* temp = editor->getCurrentPageNode();
        for (int i = 0; i < this->n - 1; i++)
           temp = temp->getNext();
        temp->setText(this->text);
    }
}

void CommandReplace::reverseApply(Editor* editor){

}