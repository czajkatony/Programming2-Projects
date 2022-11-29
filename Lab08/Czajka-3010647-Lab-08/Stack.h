/**
@Author: Tony Czajka 3010647
@File: Stack.h
@Date: 10/6/21
@Brief:This is the header file for the Stack class which is the data structure that models the elevator in this lab.
**/
#ifndef STACK_H
#define STACK_H
#include "StackInterface.h"
#include "Node.h"
#include <stdexcept>
#include <string>

template <typename T>
class Stack
{
public:

/**
* @pre Stack has not been created yet
* @post m_top is set to nullptr and length is set to 0.
* @param none
* @throw none
* @return none
**/
  Stack();
  
 /**
* @pre Stack has been created to be destructed.
* @post pop is performed on the stack untill it is empty.
* @param none
* @throw none
* @return none
**/
  ~Stack();
  
 /**
* @pre Needs to be performed on a valid stack object.
* @post None, constant method.
* @param none
* @throw none
* @return bool, if true that means the stack is empty, if false then it has values in it.
**/
  bool isEmpty()const;
 
 /**
* @pre Needs to be performed on a valid stack object.
* @post Node is added to the stack, m_top is reassigned to the new top.
* @param T value. This is what gets put into a Node which gets put on the top of the stack.
* 		 Since its templated, it can be a value of type T.
* @throw None. In this scenario there is no reason push shouldn't be able to be performed.
* @return none
**/
  void push(const T value);
 
 /**
* @pre Stack is not empty.
* @post Top node is removed and m_top is reassigned to the next node.
* @param none
* @throw runtime_error if pop is attmepted on an empty stack.
* @return none
**/
  void pop();
 
 /**
* @pre Stack is not empty
* @post none, const
* @param none
* @throw none
* @return A value T which represents the entry of the top node in the stack.
**/
  T peek()const;
 
 /**
* @pre Valid stack object has been created and is being called with getLength.
* @post none, const
* @param none
* @throw none
* @return An int that represents how many nodes are present in the stack.
**/
  int getLength()const;
private:
  Node<T>* m_top;
  int length;
};
#include "Stack.cpp"
#endif
