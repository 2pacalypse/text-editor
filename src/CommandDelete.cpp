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
    //find the n'th line
    size_t i = editor.getCurrentPage() * editor.getNumLinesPerPage() + 1;
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
    //store the deleted text for the reverse operation.
    this->deletedText = temp->getText();

    //depending on the location of the deletion, there are cases

    //if the deletion is before the current page
    if ((this->n - 1) / editor.getNumLinesPerPage() < editor.getCurrentPage())
    {
        // if there is a node after the current page, the new current page is just the next line.
        if (editor.getCurrentPageNode()->getNext() != editor.getList()->getTail())
        {
            editor.setCurrentPageNode(editor.getCurrentPageNode()->getNext());
        }
        else
        {
            //otherwise go to the previous page as there isn't any node to show at the current page.
            editor.decrementCurrentPageNode();
            editor.setCurrentPage(editor.getCurrentPage() - 1);
        }
    }
    else if ((this->n - 1) / editor.getNumLinesPerPage() > editor.getCurrentPage())
    {
        //if the deletion is after the current page, nothing changes.
    }
    else
    {
        //if the deletion is at the current page and if we delete the first line of the page
        if (temp == editor.getCurrentPageNode())
        {
            if (temp->getNext() != editor.getList()->getTail())
            {
                // if there is a node after the first line, it becomes the first line
                editor.setCurrentPageNode(temp->getNext());
            }
            else if (temp->getPrev() != editor.getList()->getHead())
            {
                // if there is not a node after the first line but there is a node before
                // we set the currentpage to currentpage - 1.
                editor.decrementCurrentPageNode();
                editor.setCurrentPage(editor.getCurrentPage() - 1);
            }
            else
            {
                //this only happens when there is not a node after or before the first line of the current page.
                // when there is zero lines left after the deletion, the currentpage is set to tail as default.
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