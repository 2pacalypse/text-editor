#ifndef COMMAND_H
#define COMMAND_H
#include "Editor.hpp"
/**
 * Virtual base class for various commands.
 * Each command has its reverse operation defined for undo purposes.
 */
class Command
{
public:
    virtual void apply(Editor &editor) = 0;
    virtual void reverseApply(Editor &editor) = 0;
    virtual ~Command(){};
};
#endif