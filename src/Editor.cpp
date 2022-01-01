#ifdef _WIN32
#define EMPTY_MARKER "\xb0"
#define ACTIVE_MARKER "\xb2"
#endif
#ifdef linux
#define EMPTY_MARKER "\u2591"
#define ACCTIVE_MARKER "\u2593"
#endif

#include "../include/Editor.hpp"
#include "../include/LinkedList.hpp"
#include "../include/ListNode.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstdio>

Editor::Editor()
{
    this->list = new LinkedList();
    this->currentPage = 0;
    this->currentPageNode = this->list->getHead()->getNext();
}

size_t Editor::getCurrentPage() const
{
    return this->currentPage;
}

LinkedList *Editor::getList() const
{
    return this->list;
}

size_t Editor::getNumLines() const
{
    return this->numLines;
}

ListNode *Editor::getCurrentPageNode() const
{
    return this->currentPageNode;
}

size_t Editor::getNumLinesPerPage() const{
    return this->numLinesPerPage;
}

void Editor::setCurrentPage(size_t val)
{
    this->currentPage = val;
}

void Editor::setNumLines(size_t val)
{
    this->numLines = val;
}

void Editor::setCurrentPageNode(ListNode *node)
{
    this->currentPageNode = node;
}

void Editor::incrementNumLines()
{
    this->numLines++;
}

void Editor::decrementNumLines()
{
    this->numLines--;
}

// append a line to the linked list
void Editor::appendLine(const std::string &line)
{
    ListNode *node = new ListNode(line);
    node->setNext(this->getList()->getTail());
    node->setPrev(this->getList()->getTail()->getPrev());
    this->getList()->getTail()->getPrev()->setNext(node);
    this->getList()->getTail()->setPrev(node);

    if (this->numLines == 0)
    {
        this->currentPageNode = this->getList()->getHead()->getNext();
    }
    this->incrementNumLines();
}

//useful for doing next
void Editor::incrementCurrentPageNode()
{
    ListNode *temp = this->currentPageNode;
    for (int i = 0; i < numLinesPerPage; i++)
        temp = temp->getNext();
    this->currentPageNode = temp;
}

//useful for doing prev
void Editor::decrementCurrentPageNode()
{
    ListNode *temp = this->currentPageNode;
    for (int i = 0; i < numLinesPerPage; i++)
        temp = temp->getPrev();
    this->currentPageNode = temp;
}

// always clear the terminal
// then print the current page
// if the current page is less than
// the number of line that should be printed,
// print a placeholder char
void Editor::printCurrentPage() const
{
    system("clear||cls");
    int i = 0;
    ListNode *temp = this->currentPageNode;
    int lineNumber = this->currentPage * numLinesPerPage + 1;
    while (i < numLinesPerPage && temp != this->list->getTail())
    {
        std::string fill;
        fill = ACTIVE_MARKER;

        std::cout << std::left << std::setw(8) <<  fill + ' ' +  std::to_string(lineNumber) + ')';
        std::cout << temp->getText() << '\n';
        i += 1;
        lineNumber += 1;
        temp = temp->getNext();
    }
    while (i < numLinesPerPage)
    {
        std::string empty;
        empty = EMPTY_MARKER;
        std::cout << std::left << std::setw(8) << empty + ' ' +  std::to_string(lineNumber) + ')';
        std::cout << '\n';
        i += 1;
        lineNumber += 1;
    }
}

//delete the old list
//and assign a new list.
void Editor::reset()
{
    if (list)
    {
        delete list;
        list = new LinkedList();
        this->currentPageNode = this->list->getHead()->getNext();
    }

    currentPage = 0;
    numLines = 0;
}

//destructor
Editor::~Editor()
{
    delete list;
}
