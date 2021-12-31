#ifndef RUNNER_H
#define RUNNER_H
#include "Editor.hpp"
#include "Command.hpp"
#include <stack>
class Runner{
    private:
        // editor is composed of a linked list + metadata (numLines, currentPage, etc.).
        Editor editor;
        // we record various actions to undo them later.
        std::stack<Command*> commandHistory;
    public:
        // runs an infinite loop for I/O from and to the terminal.
        void run();
        // reads the input command from the standard input and applies it.
        void applyNextCommand();

        

};
#endif