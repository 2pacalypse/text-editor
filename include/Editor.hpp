#ifndef EDITOR_H
#define EDITOR_H
#include "ListNode.hpp"
#include "LinkedList.hpp"
#include <string>
#include <stack>
class Editor
{
private:
    // The lines of the text file is stored with a linked list.
    LinkedList *list;
    // The line at which the page starts. e.g. 1st, 11th, 21th, 31th node of the linked list.
    // This has uses when the user switches pages.
    ListNode *currentPageNode;
    // The current page number.
    size_t currentPage = 0;
    // The total number of lines in the text.
    size_t numLines = 0;
    // The number of lines that should be displayed in each page.
    const size_t numLinesPerPage = 10;

public:
    // constructor
    Editor();
    // destructor
    ~Editor();
    // getters
    size_t getCurrentPage() const;
    size_t getNumLines() const;
    LinkedList *getList() const;
    ListNode *getCurrentPageNode() const;
    size_t getNumLinesPerPage() const;

    // setters
    void setCurrentPage(size_t val);
    void setNumLines(size_t val);
    void setCurrentPageNode(ListNode *node);

    // shortcut for numLines++
    void incrementNumLines();
    // shortcut for numLines--
    void decrementNumLines();

    // shortcut for going to the next page.
    void incrementCurrentPageNode();
    // shortcut for going to the previous page.
    void decrementCurrentPageNode();

    // appends a line with the string content.
    // useful when opening a new file.
    void appendLine(const std::string &line);

    //resets the state of this editor.
    //useful when opening a file while another one is already open.
    void reset();

    //prints the current page starting from the line pointed by currentPageNode.
    void printCurrentPage() const;
};
#endif