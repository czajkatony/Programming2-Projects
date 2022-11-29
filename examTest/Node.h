/**
@Author: Tony Czajka 3010647
@File: Node.h
@Date: 10/19/21
@Brief: This is the header file for the Node class. The nodes are the building blocks
		for the list structure.
**/
#ifndef NODE_H
#define NODE_H
#include <string>
template<typename T>
class Node
{
private:
  T m_entry;
  Node<T>* m_next;

public:

/**
* @pre none
* @post m_entry is set to entry and m_next is set to nullptr
* @param T entry, this is what the node holds
* @throw none
* @return none
**/
Node(T entry);

/**
* @pre node is created and has a valid T entry.
* @post none, const
* @param none
* @throw none
* @return none
**/
T getEntry()const;

/**
* @pre T entry is a valid data type. Node exists that Entry is being set for.
* @post m_entry is set to equal the parameter entry.
* @param T entry, what the node is set to.
* @throw none
* @return none
**/
void setEntry(T entry);

/**
* @pre none
* @post none, const
* @param none
* @throw none
* @return Node<T> pointer, which points to the next Node that it is linked to.
**/
Node<T>* getNext()const;

/**
* @pre Node<T>* is a valid Node pointer.
* @post m_next is set to equal the parameter next.
* @param Node<T>* next, which is the pointer towards the node that is being linked with
		 the current node.
* @throw none
* @return none
**/
void setNext(Node<T>* next);
};
#include "Node.cpp"
#endif
