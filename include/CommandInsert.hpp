#ifndef COMMANDINSERT_H
#define COMMANDINSERT_H
#include "Command.hpp"

class CommandInsert : public Command
{
private:
    // The line number for insertion.
    size_t n;
    // The text to be inserted.
    std::string text;
    // The total number of lines before insertion. This is for the reverse action.
    size_t numLinesBeforeInsert;

public:
    CommandInsert(size_t n, const std::string &text);
    void apply(Editor &editor);
    void reverseApply(Editor &editor);
};
#endif