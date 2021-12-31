#include <stack>
#include <string>
#include <iostream>
#include "include/Runner.hpp"
int main(){
    //entry point of the program
    Runner* runner = new Runner();
    //enters the infinite loop
    runner->run();
    //upon the 'quit' command, deallocates the memory and terminates.
    delete runner;
}