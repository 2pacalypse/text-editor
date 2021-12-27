#ifndef COMMANDNEXT_H
#define COMMANDNEXT_H
#include "Command.hpp"

class CommandNext : public Command{
    public:
        void apply(Editor& editor);
        void reverseApply(Editor& editor);  
};
#endif