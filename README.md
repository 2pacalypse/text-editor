# Simple Text Editor

Simple Text Editor project for a data structures course. Written in C++, it is a command line application with basic functionalities.

![Editor right after opening.](D:\murat\desktop\project\images\opened.png)

## Compilation

- `g++ ./include/*.hpp ./src/*.cpp main.cpp -o editor`. 

- Built and run successfully with `g++ 9.2.0`.

## Commands

| Command          | Description                                                  | Notes                                                        | Pushed to the undo stack? |
| :--------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------- |
| `open fileName`  | Opens the specified file.                                    | Informs the user in case the file is not found, or cannot be opened.<br />If the file is opened successfully, the undo stack is cleared for the new file.<br /> | :x:                       |
| `save fileName`  | Saves the current state of the editor to the specified file. | Informs the user in case the content cannot be written to the file. | :x:                       |
| `insert n text`  | Inserts the specified text to the n<sup>th</sup> line.       | Informs the user if $n \leq 0$.<br />If there are $t$ lines in the file already, and $n > t$, the lines $t + 1, t + 2, ..., n - 1$ are filled with the empty string. Otherwise, when $n \leq t$, the line is inserted after ${n-1}^{th}$ line. | :white_check_mark:        |
| `delete n`       | Deletes the n<sup>th</sup> line.                             | Informs the user if $n \leq 0$ or $n > t$, if the total number of lines in the file is $t$. | :white_check_mark:        |
| `move n m`       | Complex action which first deletes the n<sup>th</sup> line, and inserts it to the m<sup>th</sup> line. | The notes of delete and insert apply.                        | :white_check_mark:        |
| `replace n text` | Replaces the n<sup>th</sup> line with the text provided.     | Informs the user if $n \leq 0$ or $n > t$ when $t $ is the total number of lines in the file. | :white_check_mark:        |
| `next`           | Displays the next page.                                      | Informs the user when there are no more next pages.          | :x:                       |
| `prev`           | Displays the previous page.                                  | Informs the user when there are no more previous pages.      | :x:                       |
| `undo`           | Reverts the last action taken.                               | Only a subset of the actions are taken into account. <br />Informs the user when there are no more actions to undo. | :x:                       |

## Design

The text editor builds on a doubly linked list where each node of the list holds a line.

```c++
class ListNode
{
private:
    ListNode *next = nullptr;
    ListNode *prev = nullptr;
    std::string text;
};
```

The implementation is the one with the dummy head and tail. This has advantages of constant time insertion to the beginning and end of the list. Also, this reduces the number of edge cases to be considered while inserting or deleting. With the dummy nodes, every insertion or deletion happens "in between two nodes" whereas with the standard implementation, edge cases occur for cases with no nodes, or one node.

```c++
class LinkedList
{
private:
    ListNode *dummy_head = nullptr;
    ListNode *dummy_tail = nullptr;
};
```

With the linked list as its key data structure, the editor is declared as follows:

```c++
class Editor
{
private:
    LinkedList *list;
    ListNode *currentPageNode;
    size_t currentPage = 0;
    size_t numLines = 0;
    const size_t numLinesPerPage = 10;
};
```

Here each node of the linked list stores a line from the opened file as explained before. Furthermore, a pointer to the first node of the current page, the index of the current page (0-indexed), the total number of nodes (lines), and also the number of lines that should be displayed in each page is stored. The extra pointer to the first node is useful because:

- When commands try to delete or insert a line, the desired node is accessed by walking from this pointer. 
- When the user wants to visit the next or previous page, they are just a fixed length (10 in our case) of nodes away from this pointer.
- When the content of the current page is going to be printed, there is no need to find the current page by traversing the list from the beginning. 

Thus, a pointer to the starting line of the current page leverages the locality regarding the operations. Instead of traversing the list from the head each time for an operation, we traverse the list from this pointer. This makes sense because if you are on the 10<sup>th</sup> page, and you want to modify the 11<sup>th</sup> page, finding the desired line in the 11<sup>th</sup>  page starting from the beginning is a waste of time. 

While thus far we were concerned with the linked lists and nodes, we need an abstraction for the various commands to alter the state of the editor as well. For this, we declare a base class as follows:

```c++
class Command
{
public:
    virtual void apply(Editor &editor) = 0;
    virtual void reverseApply(Editor &editor) = 0;
    virtual ~Command(){};
};
```

This base class has pure virtual functions, making it an abstract class. If any of the derived classes do not implement the `apply` or `reverseApply`, they become abstract and cannot be instantiated too. The idea here is to access each command with the base pointer `Command*` and take advantage of  the run-time polymorphism. This is understood better when having a look at the `Runner` class.

```c++
class Runner
{
private:
    Editor editor;
    std::stack<Command *> commandHistory;
public:
    void run();
    void applyNextCommand();
};
```

This class is the one running the program from the `main.cpp`. The first member function runs an infinite loop continuously to print to standard output and read from the standard input. Taking the user input is done with the helper function `applyNextCommand` inside the `run`. The helper function creates a suitable command such as `CommandReplace`, `CommandDelete`, tries to apply the command, and pushes it to the history stack if the operation was successful.  Then, when the user wants to undo the last action, we pop the last action, which is a `Command*`. Calling `reverseApply` on this base pointer invokes the`reverseApply` method of the derived class. This is the reason we use virtual functions.

Each child command then stores relevant data so that both `apply` and `reverseApply` works as they are supposed to. For example, `CommandReplace` has the following declaration.

```c++
class CommandReplace : public Command
{
private:
    size_t n; // The line number at which the text gets replaced.
    std::string text; // The replacement text for the line.
    std::string textBeforeReplace; // The text before the replacement for the reverse operation.
    
public:
    CommandReplace(size_t n, const std::string &text);
    void apply(Editor &editor);
    void reverseApply(Editor &editor);
};
```

Then for the reverse operation, one can make use of the work that has already been done like this:

```c++
void CommandReplace::reverseApply(Editor &editor)
{
    CommandReplace reverseCommand = CommandReplace(this->n, this->textBeforeReplace);
    reverseCommand.apply(editor);
}
```

The reverse operation uses the logic for the `CommandReplace::apply` instead of writing the code from the scratch. The same reasoning suggests using  `CommandInsert::apply` for `CommandDelete::reverseApply`  and vice versa. This way we leverage modularity.

## Screenshots

![Error after trying to next.](D:\murat\desktop\project\images\nonextpage.PNG)

![Out of bounds error after trying to delete.](D:\murat\desktop\project\images\deleteoob.PNG)

