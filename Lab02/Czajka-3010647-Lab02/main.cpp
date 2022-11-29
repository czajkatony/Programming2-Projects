/**
@Author: Tony Czajka 3010647
@File:main.cpp
@Date: 9/16/2021
@Brief:This is the main that runs the program.
**/
#include<iostream>
#include "Executive.h"
int main(int argc, char* argv[])
{
	if(argc<2)
	{
		std::cout<<"Incorrect number of parameters!\n";
	}
	else
	{
		Executive exec(argv[1]);
		exec.run();
	}

	return(0);
}
