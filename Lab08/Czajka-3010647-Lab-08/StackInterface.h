/**
@Author: Tony Czajka 3010647
@File: StackInterface.h
@Date: 10/6/21
@Brief: This is the file for the interface for types of stacks. It lists out the required
		methods needed for something to be a stack.
**/
#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H
#include <string>

template <typename T>
class StackInterface
{

public:
  virtual ~StackInterface();
  virtual bool isEmpty()const=0;
  virtual void push(const T value)=0;
  virtual void pop()=0;
  virtual T peek()const =0;


private:

};

#endif
