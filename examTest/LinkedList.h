/**
@Author: Tony Czajka 3010647
@File: LinkedList.h
@Date: 10/19/21
@Brief: This is the header file for the Linked List class, it outlines all the methods
        and variable sused by the Linked list class including the ones required by
        the list interface.
**/
#ifndef LINKED_LIST_H
#define LINKED_LIST_
#include "Node.h"
#include "ListInterface.h"
#include <stdexcept>
#include <iostream>

template <typename T>
class LinkedList
{
private:
  Node<T>* m_front;
  int m_length;

public:

LinkedList();
~LinkedList();

/**
* @pre The index is valid
* @post The entry is added to the list at the index, increasing length by 1
* @param index, position to insert at (1 to length+1)
* @param entry, value/object to add to the list
* @throw std::runtimListe_error if the index is invalid
*/
void insert(int index, T entry);

/**
* @pre The index is valid
* @post The entry at given position is removed, reducing length by 1
* @param index, position to insert at (1 to length)
* @throw std::runtime_error if the index is invalid
*/
void remove(int index);

/**
* @pre The index is valid
* @post None
* @param index, position to insert at (1 to length)
* @throw std::runtime_error if the index is invalid
*/
T getEntry(int index) const;

/**
* @pre None
* @post List is empty
* @throw None
*/
void clear();

/**
* @pre The index is valid (must already exist)
* @post Given entry overrides the entry at the given index
* @param index, position to override at (1 to length)
* @param entry, value/object to place at given index
* @throw std::runtime_error if the index is invalid
*/
void setEntry(int index, T entry);

/**
* @pre None
* @post None
* @return the length of the list is returned
*/
int length() const;

void reverse();

};
#include "LinkedList.cpp"
#endif
