#include "../include/CommandInsert.hpp"
#include "../include/CommandDelete.hpp"

CommandInsert::CommandInsert(size_t n, const std::string &text)
{
    this->n = n;
    this->text = text;
}

void CommandInsert::apply(Editor &editor)
{
    if ((int)this->n <= 0)
    {
        delete this;
        throw "Argument out of bounds.";
    }

    this->numLinesBeforeInsert = editor.getNumLines();
    if (editor.getNumLines() < this->n)
    {
        while (editor.getNumLines() < this->n - 1)
        {
            editor.appendLine("");
        }
        editor.appendLine(this->text);
    }
    else
    {
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

        ListNode *node = new ListNode(this->text);
        node->setNext(temp);
        node->setPrev(temp->getPrev());
        temp->getPrev()->setNext(node);
        temp->setPrev(node);

        if ((this->n - 1) / editor.getNumLinesPerPage() < editor.getCurrentPage())
        {
            editor.setCurrentPageNode(editor.getCurrentPageNode()->getPrev());
        }
        else if ((this->n - 1) / editor.getNumLinesPerPage() > editor.getCurrentPage())
        {
        }
        else
        {
            if (temp == editor.getCurrentPageNode())
            {
                editor.setCurrentPageNode(node);
            }
        }

        editor.incrementNumLines();
    }
}

void CommandInsert::reverseApply(Editor &editor)
{
    if (numLinesBeforeInsert < this->n)
    {
        for (size_t i = this->n; i > this->numLinesBeforeInsert; i--)
        {
            CommandDelete reverseCommand = CommandDelete(i);
            reverseCommand.apply(editor);
        }
    }
    else
    {
        CommandDelete reverseCommand = CommandDelete(this->n);
        reverseCommand.apply(editor);
    }
}