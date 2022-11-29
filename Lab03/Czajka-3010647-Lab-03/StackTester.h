/**
@Author: Tony Czajka 3010647
@File: StackTester.h
@Date: 9/25/2021
@Brief:This is the header file for the Stack Tester class which runs the functions
of testing things on the stack.
**/
#ifndef STACK_TESTER_H
#define STACK_TESTER_H
#include "Node.h"
#include "StackOfChars.h"
#include <iostream>
class StackTester
{
	public:
	StackTester();
	void runTests();
	
	private:
/**
* @pre none
* @post creates test object and only tests if a newly created stack is empty or not and messgaes in the terminal
* @param none
* @throw none
**/	
	void test01(); //newly created stack is empty
	
/**
* @pre none
* @post creates test object and checks if pushing on an empty stack makes it non empty
* @param none
* @throw none
**/	
	void test02();//push on empty stack makes it non empty
	
/**
* @pre none
* @post creates test object and checks if popping all elements makes a stack empty
* @param none
* @throw none
**/	
	void test03();//popping all elements makes stack empty:
	
/**
* @pre none
* @post creates test object and check if peek matches the last pushed value
* @param none
* @throw none
**/	
	void test04();//peek matches last pushed value
	
/**
* @pre none
* @post creates test object and checks if the next node becomes the top node after popping.
* @param none
* @throw none
**/	
	void test05();//popping makes the next node the new top node
	
/**
* @pre none
* @post creates test object and pushes 4 values onto the stack, then checks if they are in the right order
* @param none
* @throw none
**/	
	void test06();//push 4 values and check if they are in proper order
	
};
#endif