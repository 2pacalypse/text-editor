#include "../include/Runner.hpp"
#include "../include/Command.hpp"
#include "../include/Editor.hpp"
#include "../include/CommandOpen.hpp"
#include "../include/CommandNext.hpp"
#include "../include/CommandPrev.hpp"
#include "../include/CommandReplace.hpp"
#include "../include/CommandDelete.hpp"
#include "../include/CommandInsert.hpp"
#include "../include/CommandMove.hpp"
#include "../include/CommandSave.hpp"
#include <iostream>
#include <stdexcept>

void Runner::applyNextCommand()
{
    std::cout << "Enter Command: ";
    std::string commandName;
    std::cin >> commandName;
    Command *command;

    if (commandName.compare("open") == 0)
    {
        std::string fileName;
        std::cin >> fileName;
        command = new CommandOpen(fileName);
        command->apply(editor);
    }
    else if (commandName.compare("save") == 0)
    {
        std::string fileName;
        std::cin >> fileName;
        command = new CommandSave(fileName);
        command->apply(editor);
    }
    else if (commandName.compare("insert") == 0)
    {
        size_t n;
        std::string text;
        std::cin >> n;
        std::getline(std::cin, text);
        command = new CommandInsert(n, text.substr(1));
        command->apply(editor);
        commandHistory.push(command);
    }
    else if (commandName.compare("delete") == 0)
    {
        size_t n;
        std::cin >> n;
        command = new CommandDelete(n);
        command->apply(editor);
        commandHistory.push(command);
    }
    else if (commandName.compare("move") == 0)
    {
        size_t n, m;
        std::cin >> n >> m;
        command = new CommandMove(n, m);
        command->apply(editor);
        commandHistory.push(command);
    }
    else if (commandName.compare("replace") == 0)
    {
        size_t n;
        std::string text;
        std::cin >> n;
        std::getline(std::cin, text);
        command = new CommandReplace(n, text.substr(1));
        command->apply(editor);
        commandHistory.push(command);
    }
    else if (commandName.compare("next") == 0)
    {
        command = new CommandNext();
        command->apply(editor);
    }
    else if (commandName.compare("prev") == 0)
    {
        command = new CommandPrev();
        command->apply(editor);
    }
    else if (commandName.compare("undo") == 0)
    {
        if (commandHistory.size() == 0){
            throw "No previous action to undo.";
        }
        command = commandHistory.top();
        commandHistory.pop();
        command->reverseApply(editor);
        delete command;
    }
    else if (commandName.compare("quit") == 0){
        while(!this->commandHistory.empty()){
            delete this->commandHistory.top();
            this->commandHistory.pop(); 
        }
        throw std::runtime_error("Quit");
    }
    else
    {
        throw "Invalid Command.";
    }
}

void Runner::run()
{
    std::string lastOperationStatus;
    while (1)
    {
        try{
            editor.printCurrentPage();
            std::cout << "\n\n";
            std::cout << "Last Operation Feedback: " << lastOperationStatus << '\n';
            applyNextCommand();
            lastOperationStatus = "Done!";
            
        }catch (const char* e){
            lastOperationStatus = e;
        }
        catch (const std::runtime_error& e){
            break;
        }

    }
}