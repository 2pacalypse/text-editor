#include "../include/CommandPrev.hpp"

void CommandPrev::apply(Editor* editor){
    if (editor->getCurrentPage() > 0){
        editor->setCurrentPage(editor->getCurrentPage() - 1);
        editor->decrementCurrentPageNode();
    }

}

void CommandPrev::reverseApply(Editor* editor){

}