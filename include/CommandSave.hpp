#ifndef COMMANDSAVE_H
#define COMMANDSAVE_H
#include "Command.hpp"
#include <string>
class CommandSave : public Command
{
private:
    // The filename for the save.
    std::string fileName;

public:
    CommandSave(const std::string &filename);
    void apply(Editor &editor);
    void reverseApply(Editor &editor);
};
#endif