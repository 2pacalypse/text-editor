#include "../include/CommandNext.hpp"

void CommandNext::apply(Editor &editor)
{
    if ((editor.getCurrentPage() + 1) * 10 < editor.getNumLines())
    {
        editor.setCurrentPage(editor.getCurrentPage() + 1);
        editor.incrementCurrentPageNode();
    }
    else
    {
        delete this;
        throw "No next page.";
    }
}

void CommandNext::reverseApply(Editor &editor)
{
}