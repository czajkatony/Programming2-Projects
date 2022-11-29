/**
@Author: Tony Czajka 3010647
@File: main.cpp
@Date: 12/1/2021
@Brief:Implements the Executive class to allow the user to interact with the pokedex

TO DO:
1) Give option to choose which tree to search.
2)Fix memory issues need to delete something when exception is thrown.
5) Test
6)comments update

**/


#include "Executive.h"

int main(int argc, char *argv[]){
	try{
		Executive exec(argv[1]);
		exec.run();
	}
	catch(std::runtime_error& e){
		std::cout<<"ERROR: "<<e.what()<<'\n';
	}
}
