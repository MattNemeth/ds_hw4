// main source code file

#include "digraph.h"
#include <string>
#include <iostream>
#include <vector>


int main() {

    std::cout << "Beginning of Assignment 4 program." << std::endl;
    std::cout << "Enter 1 when you have finished entering in all tasks." << std::endl;
    std::cout << std::endl;

    std::string inputs[50]; //array of strings. max of 50 tasks
    std::vector<std::string> tasks;
    std::string task;
    int taskCount = 0;

    while(1){
        std::cout << "Input a string for task " << taskCount << ": ";
        getline(std::cin, task);
	tasks.push_back(task);
	//tasks[taskCount] = task;
        // std::cout << "You entered: " << task << std::endl;


	if (task == "1"){
		break;
	}




        taskCount++; //increment counter
	//add the vertex here

    }


    std::cout << "Task entering is completed.\n" << std::endl;
    std::cout << "Task list: " << std::endl;
    for(int i=0; i < taskCount; i++){
	    std::cout << i << ".) " << tasks[i] << std::endl;
    } 
    std::cout << std::endl;

    std::cout << "To add the edges, enter which task needs to be completed first.\n";
    std::cout << "Use the number to the left of each task above.\n";
    std::cout << "For example:" << std::endl << "3 1 indicates task 3 must precede task 1" << std::endl;
    std::cout << "7 5 indicates task 7 must precede task 5" << std::endl;
    std::cout << "Enter 1 to stop." << std::endl;

    std::string input = "";

    while(1){
	    std::cout << "Enter which task comes first: " << std::endl;
	    getline(std::cin, input); 

	    if(input == "1"){
		    break;
	    }

	    

    }

    return 0;
}
