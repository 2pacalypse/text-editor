#ifndef COMMANDPREV_H
#define COMMANDPREV_H
#include "Command.hpp"

class CommandPrev : public Command{
    public:
        void apply(Editor& editor);
        void reverseApply(Editor& editor);
            
};
#endif