// main source code file

#include "digraph.h"
#include <string>
#include "iostream"


int main() {

    std::cout << "Beginning of Assignment 4 program." << std::endl;
    std::cout << "Enter 1 when you have finished entering in all tasks." << std::endl;

    std::string inputs[50]; //array of strings. max of 50 tasks
    std::string task;
    int i = 0;

    while(1){
        std::cout << "Input a string for task " << i << ": ";
        getline(cin, task);
	inputs[i] = task;
        std::cout << "You entered is: " << task << std::endl;


	if (task == '1'){
		break;
	}




        i++; //increment counter

    }

    return 0;
}
