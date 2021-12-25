#ifndef COMMAND_H
#define COMMAND_H
#include "Editor.hpp"

class Command{
    public:
        virtual void apply(Editor* editor) = 0;
        virtual void reverseApply(Editor* editor) = 0;
};
#endif