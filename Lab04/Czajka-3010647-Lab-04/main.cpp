/**
@Author: Tony Czajka 3010647
@File: main.cpp
@Date: 10/6/21
@Brief:This is the main.cpp file for the program that utilizes the Executive class to output a descritpion of the line and elevator
		when prompted. It also takes in the file name that is being read from the terminal.
**/
#include "Executive.h"
#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[]) {

	Executive* exec=new Executive(argv[1]);
	try{
		exec->run();
	}
	catch(std::runtime_error& e){
		std::cout<<"ERROR: "<<e.what()<<'\n';
	}
	delete exec;

  return 0;
}


//do comments
