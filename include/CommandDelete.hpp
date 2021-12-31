#ifndef COMMANDDELETE_H
#define COMMANDDELETE_H
#include "Command.hpp"

class CommandDelete : public Command{
    private:
        // The line number to be deleted.
        size_t n;
        //the text at the deleted line for the reverse operation.
        std::string deletedText;
    public:
        CommandDelete(size_t n);
        void apply(Editor& editor);
        void reverseApply(Editor& editor);
            
};
#endif