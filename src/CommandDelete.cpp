#include "../include/CommandDelete.hpp"
#include "../include/ListNode.hpp"
#include "../include/CommandInsert.hpp"

CommandDelete::CommandDelete(size_t n)
{
    this->n = n;
}
void CommandDelete::apply(Editor &editor)
{
    if (this->n <= 0 || this->n > editor.getNumLines())
    {
        delete this;
        throw "Argument out of bounds.";
    }
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

    if ((this->n - 1) / 10 < editor.getCurrentPage())
    {
        if (editor.getCurrentPageNode()->getNext() != editor.getList()->getTail())
        {
            editor.setCurrentPageNode(editor.getCurrentPageNode()->getNext());
        }
        else
        {
            editor.decrementCurrentPageNode();
            editor.setCurrentPage(editor.getCurrentPage() - 1);
        }
    }
    else if ((this->n - 1) / 10 > editor.getCurrentPage())
    {
    }
    else
    {
        if (temp == editor.getCurrentPageNode())
        {
            if (temp->getNext() != editor.getList()->getTail())
            {
                editor.setCurrentPageNode(temp->getNext());
            }
            else if (temp->getPrev() != editor.getList()->getHead())
            {
                editor.decrementCurrentPageNode();
                editor.setCurrentPage(editor.getCurrentPage() - 1);
            }
            else
            {
                editor.setCurrentPageNode(editor.getList()->getTail());
            }
        }
    }

    temp->getPrev()->setNext(temp->getNext());
    temp->getNext()->setPrev(temp->getPrev());

    delete temp;
    editor.decrementNumLines();
}

void CommandDelete::reverseApply(Editor &editor)
{
    CommandInsert reverseCommand = CommandInsert(this->n, this->deletedText);
    reverseCommand.apply(editor);
}