#ifndef COMMANDOPEN_H
#define COMMANDOPEN_H
#include "Command.hpp"
#include <string>
class CommandOpen : public Command
{
private:
    // The filename to be opened.
    std::string fileName;

public:
    CommandOpen(const std::string &filename);
    void apply(Editor &editor);
    void reverseApply(Editor &editor);
};
#endif