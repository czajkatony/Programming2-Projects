/**
@Author: Tony Czajka 3010647
@File: StackInterface.h
@Date: 9/25/2021
@Brief:This is the header file for the StackInterface templated Interface, this will
be the interface StackOfChar is based on.
**/
#ifndef STACK_H
#define STACK_H

#include <stdexcept>
//Don't add
template <typename T>
class StackInterface
{
	public:
	virtual void push(T entry) = 0;
	virtual void pop() = 0;
	virtual T peek() const = 0;
	virtual bool isEmpty() const = 0;
    virtual ~StackInterface() {} //virtual destructor

};

#endif