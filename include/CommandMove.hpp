#ifndef COMMANDMOVE_H
#define COMMANDMOVE_H
#include "Command.hpp"
#include "CommandInsert.hpp"
#include "CommandDelete.hpp"

class CommandMove : public Command{
    private:
        size_t n;
        size_t m;
        CommandDelete* subcommand1;
        CommandInsert* subcommand2;
    public:
        CommandMove(size_t n, size_t m);
        ~CommandMove();
        void apply(Editor& editor);
        void reverseApply(Editor& editor);  
};
#endif