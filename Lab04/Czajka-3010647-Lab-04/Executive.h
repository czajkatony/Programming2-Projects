/**
@Author: Tony Czajka 3010647
@File: Executive.h
@Date: 10/6/21
@Brief:This is the header file for the Executive class. This defines and outlines the methods used to implement cases of a Queue and a Stack to represent
		a line and elevator. It reads in commands from a text file to fill and empty the elevator and line accordingly, and outputs a description of the status
		of the elevator and line into terminal when prompted by the text file.
**/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Node.h"
#include "Queue.h"
#include "Stack.h"
#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>

class Executive
{
private:

std::string m_filename;
std::string actionCode;
Stack<std::string>* elevator;
Queue<std::string>* line;
public:

/**
* @pre none
* @post m_filename set to filename passed into function. Elevator points to a new Stack
		and line points to a new queue.
* @param std::string filename, this is the name needed to open the input file.
* @throw none
* @return none
**/
Executive(std::string filename);

/**
* @pre Executive class object exists to deconstruct
* @post elevator and line are deleted.
* @param none
* @throw none
* @return none
**/
~Executive();

/**
* @pre Needs valid action Codes input from the input.txt.
* @post Any of 5 methods can be called which either push nodes onto the queue, push nodes onto the stack pop nodes from the queue
		nodes can be popped from the stack, or a summary of the elevator and line conditions
		can be printed to terminal.
* @param none
* @throw throws std::runtime_error if any of the action codes input from the file do not match one of the predetermined 4 options.
* @return none
**/
void run();

/**
* @pre Needs a name and a valid queue created (line)
* @post New node enqueued onto the back of the queue containing someones name.
* @param std::string name, the name that the node contains representing the person who
		 just got into line.
* @throw none
* @return none
**/
void wait(std::string name);

/**
* @pre line cannot be empty
* @post as many nodes that can be pushed onto the elevator stack get dequeued from the line and pushed onto the stack.
* @param none
* @throw std::runtime_error if the line is empty 
* @return none
**/
void pickUp();

/**
* @pre people need to be inside the elevator for a drop off to occur, cannot drop off
	   more than 7 people at any given time. Also, cannot drop off mroe people than are in the elevator at that time.
* @post nodes popped from elevator. The number popped is given by the parameter, can't be less than 0 or greater than 7.
* @param int num, represents how many people will get dropped off from the elevator.
* @throw runtime_error if num is >7 or less than 0 OR if num is larger than the current amount of people in the elevator.
* @return none
**/
void dropOff(int num);

/**
* @pre valid queue and stack have been created.
* @post none, const
* @param none
* @throw none
* @return none
**/
void inspection()const;
};

#endif
