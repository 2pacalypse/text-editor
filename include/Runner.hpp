#ifndef RUNNER_H
#define RUNNER_H
#include "Editor.hpp"
#include "Command.hpp"
#include <stack>
class Runner{
    private:
        Editor editor;
        std::stack<Command*> commandHistory;
    public:
        void run();
        void applyNextCommand();

};
#endif