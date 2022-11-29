/**
@Author: Tony Czajka 3010647
@File: StackOfChars.h
@Date: 9/25/2021
@Brief: This is the header file for StackOfChar class. This is based on the interface
Stack Interface and is what interacts with the stack.
**/
#ifndef STACKOFCHARS_H
#define STACKOFCHARS_H
#include "StackInterface.h"
#include "Node.h"
#include <iostream>

//Our stack will implement the StackInterface but of a stack specifically filled with chars.
//We'll learn in lecture how to make a templated Node and then a templated Stack
class StackOfChars : public StackInterface<char> 
{
	private:
	Node* m_top;
	
	public:

/**
* @pre None
* @post m_top is created and pointed to null
* @param None
* @throw None
**/	
	StackOfChars();

	StackOfChars(const StackOfChars& orig); //what does this do??

    ~StackOfChars();
	
	void operator=(const StackOfChars& rhs);
	

/**
* @pre if m_top=nullptr, m_top needs to be hard set to the new node
* @post m_top is pointed to a new Node containing the entry that is passed in.
* @param char entry, this is what the new top node will hold
* @throw None
**/	
	void push(char entry);
	

/**
* @pre Stack is non-empty
* @post Top element is removed from the stack
* @param none
* @throw std::runtime_error if pop attempted on an empty stack
**/	
	void pop();

/**
* @pre Stack is non-empty
* @post const, only returning a char value
* @param none
* @throw std::runtime_error if peek attempted on an empty stack
**/	
	char peek() const; //should peek throw an exception?

/**
* @pre Stack is non-empty
* @post const, only returning a bool value to signify an empty stack or not
* @param none
* @throw none
**/	
	bool isEmpty() const;

};
#endif