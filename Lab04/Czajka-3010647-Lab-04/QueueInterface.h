/**
@Author: Tony Czajka 3010647
@File: QueueInterface.h
@Date: 10/6/21
@Brief: This is the interface file for Queues, which lists all the required methods
		in order to be considered a queue.
**/
#ifndef QUEUE_INTERFACE_H
#define QUEUE_INTERFACE_H
#include <string>
template <typename T>
class QueueInterface
{
public:
  virtual ~QueueInterface();
  virtual void enqueue(T entry) = 0;
  virtual void dequeue() = 0;
  virtual T peekFront() const = 0;
  virtual bool isEmpty() const = 0;
};
#endif
