/**
@Author: Tony Czajka 3010647
@File: ParserDriver.h
@Date: 9/25/2021
@Brief:This is the header file for the ParserDriver class which handels the user input and
determines whether or not the string of curly braces is balanced or not
**/
#ifndef PARSER_DRIVER_H
#define PARSER_DRIVER_H
#include <iostream>
#include <stdexcept>
#include <string>
#include "Node.h"
#include "StackOfChars.h"
class ParserDriver
{
	private:
	StackOfChars* stack;
	std::string userString;
	public:
/**
* @pre none
* @post creates a Parser Driver test object with a fresh StackOfChars
* @param none
* @throw none
**/	
	ParserDriver();

/**
* @pre none
* @post deconstructs by deleting the stack.
* @param none
* @throw none
**/	
	~ParserDriver();

/**
* @pre none
* @post runs user input, has a try catch block to catch any exceptions.
* @param none
* @throw none
**/	
	void runParserDriver();
	
/**
* @pre must have a valid ParserDriver object
* @post inputs a string from the user, if its a '{' then it pushes onto the stack, for every '}' it pops the stack
		if isEmpty returns true at the end then it is balanced otherwise it is not
* @param none
* @throw Throws exceptions if 1) string starts with a '}' because we can't pop on an empty stack 2) if the sequence
		 is unbalanced since otherwise this would try to pop an empty stack.
**/	
	void userInput();
};
#endif