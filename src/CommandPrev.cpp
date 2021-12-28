#include "../include/CommandPrev.hpp"

void CommandPrev::apply(Editor& editor){
    if (editor.getCurrentPage() > 0){
        editor.setCurrentPage(editor.getCurrentPage() - 1);
        editor.decrementCurrentPageNode();
    }else{
        throw "No previous page.";
    }

}

void CommandPrev::reverseApply(Editor& editor){

}