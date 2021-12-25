#ifndef EDITOR_H
#define EDITOR_H
#include "ListNode.hpp"
#include "LinkedList.hpp"
#include <string>
#include <stack>
class Editor{
    private:
        LinkedList *list = nullptr;
        size_t currentPage = 0;
        size_t numLines = 0;
        ListNode* currentPageNode = nullptr;
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

        void appendLine(const std::string& line);        

        void printCurrentPage() const;

        


        //void open(const std::string& fileName);
        //void save(const std::string& fileName);
        //void insertLine(size_t n, const std::string& text);
        //void deleteLine(size_t n);
        //void moveLines(size_t n, size_t m);
        //void replaceLine(size_t n, std::string& text);
        //void next();
        //void prev();
        //void undo();

};
#endif