/**
@Author: Tony Czajka 3010647
@File: Queue.h
@Date: 10/6/21
@Brief:This is the header file for the Queue class. This is a data structure that is
		FIFO and links information together using nodes.
**/
#ifndef QUEUE_H
#define QUEUE_H

#include "QueueInterface.h"
#include "Node.h"
#include <stdexcept>
#include <string>
template <typename T>
class Queue
{
private:
  Node<T>* m_front;
  Node<T>* m_back;
  int length;


public:

/**
* @pre Queue has not been created yet
* @post m_front and m_back are set to nullptr
* @param none
* @throw none
* @return none
**/
  Queue();
 
 /**
* @pre Queue object has been created that needs destructing.
* @post dequeue is ran untill queue is empty, emptying the queue.
* @param none
* @throw none
* @return none
**/
  ~Queue();
 
 /**
* @pre Valid queue object is being added to, valid entry is given
* @post New Node is created and placed at the back of the queue. Length is increased by 1
* @param T entry, this is the piece of data that will go into the node which is then
		 placed in the queue.
* @throw none
* @return none
**/
  void enqueue(T entry);
 
 /**
* @pre Must be an object in the queue.
* @post m_front is deleted and reassigned, length decreases by one.
* @param none
* @throw std::runtime_error if dequeue is attempted on an empty queue.
* @return none
**/
  void dequeue();

/**
* @pre Queue cannot be empty, must have something to target with peekFront
* @post none, const.
* @param none
* @throw std::runtime_error if peekFront is attempted on an empty queue.
* @return none
**/
  T peekFront()const;

/**
* @pre Valid queue object exists
* @post none, const
* @param none
* @throw none
* @return bool, true if there are no nodes in the queue, and false if there exists at least
		  one node in the queue.
**/
  bool isEmpty()const;

/**
* @pre Valid queue object exists
* @post none const
* @param none
* @throw none
* @return int, tracks how many nodes are in the queue at any time.
**/
  int getLength()const;


};
#include "Queue.cpp"
#endif
