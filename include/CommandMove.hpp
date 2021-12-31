#ifndef COMMANDMOVE_H
#define COMMANDMOVE_H
#include "Command.hpp"
#include "CommandInsert.hpp"
#include "CommandDelete.hpp"

class CommandMove : public Command
{
private:
    // The line number from which the text moves.
    size_t n;
    // The line number to which the text moves.
    size_t m;
    // Move is modeled as first deletion and then insertion.
    CommandDelete *subcommand1;
    CommandInsert *subcommand2;

public:
    CommandMove(size_t n, size_t m);
    ~CommandMove();
    void apply(Editor &editor);
    void reverseApply(Editor &editor);
};
#endif