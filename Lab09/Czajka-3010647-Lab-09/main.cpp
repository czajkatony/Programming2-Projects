/**
@Author: Tony Czajka 3010647
@File: main.cpp
@Date: 12/1/2021
@Brief:Implements the Executive class to allow the user to interact with the pokedex
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
