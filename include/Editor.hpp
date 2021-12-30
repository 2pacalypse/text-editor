#ifndef EDITOR_H
#define EDITOR_H
#include "ListNode.hpp"
#include "LinkedList.hpp"
#include <string>
#include <stack>
class Editor{
    private:
        LinkedList *list = nullptr;
        ListNode* currentPageNode = nullptr;
        size_t currentPage = 0;
        size_t numLines = 0;
    public:
        Editor();
        size_t getCurrentPage() const;
        size_t getNumLines() const;
        LinkedList* getList() const;
        ListNode* getCurrentPageNode() const;
        

        void setCurrentPage(size_t val);
        void setNumLines(size_t val);
        void incrementNumLines();
        void decrementNumLines();
        void incrementCurrentPageNode();
        void decrementCurrentPageNode();
        void setCurrentPageNode(ListNode* node);

        void appendLine(const std::string& line);        
        void reset();

        void printCurrentPage() const;

};
#endif