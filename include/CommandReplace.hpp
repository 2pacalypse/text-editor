#ifndef COMMANDREPLACE_H
#define COMMANDREPLACE_H
#include "Command.hpp"

class CommandReplace : public Command
{
private:
    // The line number at which the text gets replaced.
    size_t n;
    // The replacement text for the line.
    std::string text;
    // The text before the replacement for the reverse operation.
    std::string textBeforeReplace;

public:
    CommandReplace(size_t n, const std::string &text);
    void apply(Editor &editor);
    void reverseApply(Editor &editor);
};
#endif