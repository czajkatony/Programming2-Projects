/**
@Author: Tony Czajka 3010647
@File: Node.cpp
@Date: 10/19/21
@Brief: This is the cpp file for the Node class, which implements the methods defined in Node.h. The Node
		class provides the building blocks for which the Linked List class is made of. This is what
		links the data types together in the List.
**/
#include "Node.h"

template <typename T>
Node<T>::Node(T entry){
  m_entry=entry;
  m_next=nullptr;
}

template <typename T>
T Node<T>::getEntry()const{
  return(m_entry);
}

template <typename T>
void Node<T>::setEntry(T entry){
  m_entry=entry;
}

template <typename T>
Node<T>* Node<T>::getNext()const{
  return(m_next);
}

template <typename T>
void Node<T>::setNext(Node<T>* next){
  m_next=next;
}
