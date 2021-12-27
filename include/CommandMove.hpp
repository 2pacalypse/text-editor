#ifndef COMMANDMOVE_H
#define COMMANDMOVE_H
#include "Command.hpp"

class CommandMove : public Command{
    private:
        size_t n;
        size_t m;
    public:
        CommandMove(size_t n, size_t m);
        void apply(Editor* editor);
        void reverseApply(Editor* editor);  
};
#endif