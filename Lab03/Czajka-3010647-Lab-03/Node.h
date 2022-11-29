/**
@Author: Tony Czajka 3010647
@File: Node.h
@Date: 9/25/2021
@Brief:This is the header file for the Node class which holds the data.
**/
#ifndef NODE_H
#define NODE_H
#include <stdexcept>
//Don't add
class Node
{
	private:
	char m_entry;
	Node* m_next;
	
	public:
/**
* @pre None
* @post Node is created, m_entry is set to entry thats passed in
* @param entry, the element to be added to the Node
* @throw None
**/
	Node(char entry);

/**
* @pre None
* @post entry is returned
* @param None
* @throw None
**/
	char getEntry() const;

/**
* @pre entry value must be a valid char
* @post entry is set to the node
* @param entry, the element to be added to the node
* @throw None
**/
	void setEntry(char entry);

/**
* @pre None
* @post Next Node is returned as a Node*
* @param none
* @throw None
**/
	Node* getNext() const;

/**
* @pre next must be pointing to a Node object
* @post next node is set to "next"
* @param next, the node that is being se to m_next
* @throw runtime_error for if the pointer next is set to null.
**/
	void setNext(Node* next);

};
#endif