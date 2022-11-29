/**
@Author: Tony Czajka 3010647
@File:main.cpp
@Date: 9/25/2021
@Brief:This is the main that runs the program.
**/
#include<iostream>
#include<string>
#include<cstring>
#include "StackTester.h"
#include "ParserDriver.h"

int main(int argc, char*argv[])
{
	if(argc<2)
	{
		std::cout<<"Incorrect number of parameters!\n";
	}
	else
	{
		if(std::strcmp(argv[1],"-t")==0)
		{
			StackTester stackTest;
			stackTest.runTests();
		}
		else if(std::strcmp(argv[1],"-p")==0)
		{
				ParserDriver balance;
				balance.runParserDriver();
		}
		else
		{
			std::cout<<"Please enter '-t' for test mode and '-p' for parser mode.\n";
		}
	}
	return(0);
}