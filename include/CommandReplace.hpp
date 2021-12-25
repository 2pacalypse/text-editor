#ifndef COMMANDREPLACE_H
#define COMMANDREPLACE_H
#include "Command.hpp"

class CommandReplace : public Command{
    private:
        size_t n;
        std::string text;
    public:
        CommandReplace(size_t n, const std::string& text);
        void apply(Editor* editor);
        void reverseApply(Editor* editor);      
};
#endif