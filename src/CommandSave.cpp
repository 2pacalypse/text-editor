#include "../include/CommandSave.hpp"
#include <fstream>
#include <iostream>
CommandSave::CommandSave(const std::string& fileName){
    this->fileName = fileName;
}

void CommandSave::apply(Editor& editor){
    std::ofstream file(this->fileName);

    if (file.is_open()){
        ListNode *temp = editor.getList()->getHead()->getNext();
        while (temp != editor.getList()->getTail()){
            file << temp->getText() << '\n';
            temp = temp->getNext();
        }
    }else{
        delete this;
        throw "Error writing output.";
    }
}

void CommandSave::reverseApply(Editor& editor){

}

