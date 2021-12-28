#ifndef COMMANDINSERT_H
#define COMMANDINSERT_H
#include "Command.hpp"

class CommandInsert : public Command{
    private:
        size_t n;
        std::string text;
        size_t numLinesBeforeInsert;
    public:
        CommandInsert(size_t n, const std::string& text);
        void apply(Editor& editor);
        void reverseApply(Editor& editor);
            
};
#endif