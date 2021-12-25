#ifndef COMMANDDELETE_H
#define COMMANDDELETE_H
#include "Command.hpp"

class CommandDelete : public Command{
    private:
        size_t n;
    public:
        CommandDelete(size_t n);
        void apply(Editor* editor);
        void reverseApply(Editor* editor);
            
};
#endif