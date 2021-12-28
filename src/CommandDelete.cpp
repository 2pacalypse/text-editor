#include "../include/CommandDelete.hpp"
#include "../include/ListNode.hpp"
#include "../include/CommandInsert.hpp"

CommandDelete::CommandDelete(size_t n)
{
    this->n = n;
}
void CommandDelete::apply(Editor &editor)
{
    if (this->n >= 1 && this->n <= editor.getNumLines())
    {
        size_t i = editor.getCurrentPage() * 10 + 1;
        ListNode *temp = editor.getCurrentPageNode();
        while (i < this->n)
        {
            i += 1;
            temp = temp->getNext();
        }
        while (i > this->n)
        {
            i -= 1;
            temp = temp->getPrev();
        }
        this->deletedText = temp->getText();
        

        
        if (temp == editor.getCurrentPageNode()){
            if (temp->getNext() != editor.getList()->getTail()){
                editor.setCurrentPageNode(temp->getNext());
            }
            else if (temp->getPrev() != editor.getList()->getHead()){  
                editor.decrementCurrentPageNode();
                editor.setCurrentPage(editor.getCurrentPage() - 1);
            }else{
                editor.setCurrentPageNode(editor.getList()->getTail());
            }
        }

        temp->getPrev()->setNext(temp->getNext());
        temp->getNext()->setPrev(temp->getPrev());
        
        delete temp;
        editor.decrementNumLines();
    }
    else
    {
        throw "Argument out of bounds.";
    }
}

void CommandDelete::reverseApply(Editor &editor)
{
    Command *reverseCommand = new CommandInsert(this->n, this->deletedText);
    reverseCommand->apply(editor);
}