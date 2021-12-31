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

/**
 * reads the user input from standard input,
 * creates the suitable command from the available children classes,
 * applies the command, and records it in the undo stack if appropriate.
 */
void Runner::applyNextCommand()
{
    std::cout << "Enter Command: ";
    // read the first word from the input.
    // e.g. open, insert, delete, move...
    std::string commandName;
    std::cin >> commandName;

    //pointer to the base class for run-time polymorphism.
    Command *command;
    if (commandName.compare("open") == 0)
    {
        // read the second argument
        std::string fileName;
        std::cin >> fileName;
        // create the command and try to apply it.
        command = new CommandOpen(fileName);
        command->apply(editor);
        // if successfuly applied, delete the command to free the memory.
        delete command;
        // when a new file opens, also clear the undo stack.
        while (!this->commandHistory.empty())
        {
            delete this->commandHistory.top();
            this->commandHistory.pop();
        }
    }
    else if (commandName.compare("save") == 0)
    {
        //read the second argument
        std::string fileName;
        std::cin >> fileName;
        // create the command and try to apply it.
        command = new CommandSave(fileName);
        command->apply(editor);
        // if successful, delete it.
        delete command;
    }
    else if (commandName.compare("insert") == 0)
    {
        //read the rest of the arguments
        size_t n;
        std::string text;
        std::cin >> n;
        std::getline(std::cin, text);
        //create the command and try to apply it.
        command = new CommandInsert(n, text.substr(1));
        command->apply(editor);
        //if successful, push it to the undo stack.
        commandHistory.push(command);
    }
    else if (commandName.compare("delete") == 0)
    {
        // read the rest of the arguments
        size_t n;
        std::cin >> n;
        // create the command and try to apply it.
        command = new CommandDelete(n);
        command->apply(editor);
        // if successful, push it to the undo stack.
        commandHistory.push(command);
    }
    else if (commandName.compare("move") == 0)
    {
        // read the rest of the arguments.
        size_t n, m;
        std::cin >> n >> m;
        // create the command and try to apply it.
        command = new CommandMove(n, m);
        command->apply(editor);
        // if successful, push it to the undo stack.
        commandHistory.push(command);
    }
    else if (commandName.compare("replace") == 0)
    {
        //read the rest of the arguments.
        size_t n;
        std::string text;
        std::cin >> n;
        std::getline(std::cin, text);
        // create the command and try to apply it.
        command = new CommandReplace(n, text.substr(1));
        command->apply(editor);
        //if successful, push it to the undo stack.
        commandHistory.push(command);
    }
    else if (commandName.compare("next") == 0)
    {
        //create the command
        command = new CommandNext();
        command->apply(editor);
        // delete it here if the command is successfully applied.
        delete command;
    }
    else if (commandName.compare("prev") == 0)
    {
        //create the command
        command = new CommandPrev();
        command->apply(editor);
        //delete it here if the command is successfuly applied.
        delete command;
    }
    else if (commandName.compare("undo") == 0)
    {
        // if the undo stack is empty, throw an exception.
        if (commandHistory.size() == 0)
        {
            throw "No previous action to undo.";
        }
        // otherwise, get the last operation applied and reverse apply it.
        command = commandHistory.top();
        commandHistory.pop();
        command->reverseApply(editor);
        // delete the command.
        delete command;
    }
    else if (commandName.compare("quit") == 0)
    {
        //before quitting, clear the undo stack.
        while (!this->commandHistory.empty())
        {
            delete this->commandHistory.top();
            this->commandHistory.pop();
        }
        // signal quit
        throw std::runtime_error("Quit");
    }
    else
    {
        // if the command is not in the vocabulary, throw an exception.
        throw "Invalid Command.";
    }
}

/**
 * infinite loop which prints the state of the editor
 * takes the user input, updates the state, prints 
 * exceptions, and quits if necessary.
 */
void Runner::run()
{
    std::string lastOperationStatus;
    while (1)
    {
        try
        {
            editor.printCurrentPage();
            std::cout << "\n\n";
            std::cout << "Last Operation Feedback: " << lastOperationStatus << '\n';

            // this waits for user input and if the given command cannot be applied
            // for some reason (invalid command, out of bounds, etc.), the thrown
            // exception is caught in the catch blocks below.
            applyNextCommand();
            lastOperationStatus = "Done!";
        }
        catch (const char *e)
        {
            //this gives information about the thrown exception after trying to apply a command.
            //e.g. (invalid command, out of bounds)
            lastOperationStatus = e;
        }
        catch (const std::runtime_error &e)
        {
            // this block only runs when user provides 'quit' as command.
            break;
        }
    }
}