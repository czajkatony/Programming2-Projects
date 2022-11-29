/**
@Author: Tony Czajka 3010647
@File: ParserDriver.cpp
@Date: 9/25/2021
@Brief:This is the cpp file for the ParserDriver class which implements the methods and variables
from the header file to allow the user to enter a string of curly braces and 
determines whether or not the string of curly braces is balanced or not
**/
#include "ParserDriver.h"

ParserDriver::ParserDriver()
{
	stack=new StackOfChars();
}

ParserDriver::~ParserDriver() 
{
	delete stack;
	
}

void ParserDriver::runParserDriver()
{
	try{
	userInput();
	}
	catch(std::exception& e)
	{
		std::cout<<e.what()<<'\n';
	}
}

void ParserDriver::userInput()
{
	std::cout<<"Please enter a string of curly braces '{' or '}' to determine wether it is balanced or not: ";
	std::cin>>userString;
	for(int i=0;i<userString.length();i++)
	{
		if(userString.at(i)=='{'||userString.at(i)=='}')
		{
			if(i==0&&userString.at(i)=='}')
			{
				throw(std::runtime_error("String is unbalanced since it started with '}'."));
			}
			else{
				if(userString.at(i)=='{')
				{
					stack->push(userString.at(i));
				}
				else if(!stack->isEmpty())
				{
					stack->pop();
				}
				else{
					throw(std::runtime_error("Sequence is not balanced."));
				}
			}
		}
		else
		{
			throw(std::runtime_error("String consisted of characters other than '{' or '}'."));
		
		}


	}
	if(stack->isEmpty())
	{
		std::cout<<"Sequence is balanced\n";
	}		
	else
	{
		std::cout<<"Sequence is not balanced\n";
	}
}