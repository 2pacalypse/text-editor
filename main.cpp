#include "include/Command.hpp"
#include "include/Editor.hpp"
#include "include/CommandOpen.hpp"
#include "include/CommandNext.hpp"
#include "include/CommandPrev.hpp"
#include "include/CommandReplace.hpp"
#include "include/CommandDelete.hpp"
#include <stack>
#include <string>
#include <iostream>
int main(){
    Editor* editor = new Editor();
    std::stack<Command*> commandHistory;

    while (1){
        editor->printCurrentPage();

        std::string commandName;
        std::cin >> commandName;
        Command *command;

        if (commandName.compare("open") == 0){
            std::string fileName;
            std::cin >> fileName;
            command = new CommandOpen(fileName);
            command->apply(editor);

        }else if (commandName.compare("save") == 0){

        }else if (commandName.compare("insert") == 0){

        }else if (commandName.compare("delete") == 0){
            size_t n;
            std::cin >> n;
            command = new CommandDelete(n);
            command->apply(editor);

        }else if (commandName.compare("move") == 0){

        }else if (commandName.compare("replace") == 0){
            size_t n;
            std::string text;
            std::cin >> n;
            std::getline(std::cin, text);
            command = new CommandReplace(n, text.substr(1));
            command->apply(editor);

        }else if (commandName.compare("next") == 0){
            command = new CommandNext();
            command->apply(editor);

        }else if (commandName.compare("prev") == 0){
            command = new CommandPrev();
            command->apply(editor);

        }else if (commandName.compare("undo") == 0){

        }else {

        }
    }

}