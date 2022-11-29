/**
@Author: Tony Czajka 3010647
@File: Bnode.h
@Date: 12/1/2021
@Brief: Defines the member methods and variables for the class.
**/

#ifndef BNODE_H
#define BNODE_H
#include "Pokemon.h"
template<typename T>
class Bnode{
private:
  Bnode<T>* left;
  Bnode<T>* right;
  T m_entry;
public:
  Bnode(T value);
  
  	/**
  * @post Left pointer is set
  * @param Bnode pointer to which the left pointer will be set to
  */
  void setLeftPtr(Bnode<T>* temp);
  
  	/**
  * @post Right pointer is set
  * @param Bnode pointer to which the Right pointer will be set to
  */
  void setRightPtr(Bnode<T>* temp);
  
 	/**
  * @post Entry is changed
  * @param entry of type T, what the node will contain
  */
  void setEntry(T entry);
 
  /**
  * @post none
  * @param none
  * @return pointer for left child
  */
  Bnode<T>* getLeftPtr()const;
  
   /**
  * @post none
  * @param none
  * @return pointer for right child
  */
  Bnode<T>* getRightPtr()const;
 
   /**
  * @post none
  * @param none
  * @return T for entry
  */
  T getEntry()const;
};

#include "Bnode.cpp"
#endif
