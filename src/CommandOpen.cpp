#include "../include/CommandOpen.hpp"
#include <fstream>
#include <iostream>
CommandOpen::CommandOpen(const std::string& fileName){
    this->fileName = fileName;
}

void CommandOpen::apply(Editor& editor){
    std::ifstream file(this->fileName);
    
    if (file.is_open()){
        editor.reset();
        std::string line;
        while (std::getline(file, line)){
            editor.appendLine(line);
        }
    }else{
        delete this;
        throw "Cannot open the file.";
    }
}

void CommandOpen::reverseApply(Editor& editor){

}

