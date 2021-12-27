#include "../include/CommandNext.hpp"

void CommandNext::apply(Editor& editor){
    if ((editor.getCurrentPage() + 1) * 10 < editor.getNumLines()){
        editor.setCurrentPage(editor.getCurrentPage() + 1);
        editor.incrementCurrentPageNode();
    }

}

void CommandNext::reverseApply(Editor& editor){

}