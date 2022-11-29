/**
@Author: Tony Czajka 3010647
@File: BinarySearchTree.h
@Date: 12/1/2021
@Brief: Defines the member methods and variables for the class.
**/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "Bnode.h"
#include "BinarySearchTreeInterface.h"
#include <stdexcept>
#include <iostream>
template <typename ItemType, typename KeyType>
class BinarySearchTree : public BinarySearchTreeInterface<ItemType, KeyType>{
private:
  


public:
Bnode<ItemType>* m_root;
  BinarySearchTree();//XXX
  ~BinarySearchTree();
  
  void setRoot(Bnode<ItemType>* newRoot);
  
  Bnode<ItemType>* getRoot();
  Bnode<ItemType>* copyTreeHelper(Bnode<ItemType>* root);
  Bnode<ItemType>* copyTree();



     /**
  * @post valid tree created, cannot be a duplicate
  * @param Item type entry, what will be added to the tree
  * @throw exception if duplicate added.
  */
  void add(ItemType entry); //XXthrows std::runtime_error if duplicate added

     /**
  * @post valid tree created, cannot be a duplicate
  * @param Kye type, this is the unique id to be used in the search
  * @throw exception if it is not in the tree
  */
  ItemType search(KeyType key) const; //XXXthrows std::runtime_error if not in tree

     /**
  * @post clears out entire array
  * @param none
  * @return none
  */
  void clear(); //Empties the tree ??||||STILL NEED TO DO
  
  
      /**
  * @post does all the deleting and recursive calling
  * @param Node ptr to allow it to be a recursive function, tells it where to act on.
  * @return 
  */
  void clearHelper(Bnode<ItemType>* root);
  

     /**
  * @post none
  * @param none
  * @return T for entry
  */
  void remove(KeyType key); //throws std::runtime_error if not in tree

  //MIGHT NEED TO PUT THESE IN PRIVATE
     /**
  * @post new node added to the tree pointing to the entry.
  * @param Bnode pointer to keep track of where is bein added to and the entry so it can be added
  * @return returns the root pointer to the new tree.
  */
  Bnode<ItemType>* addHelper(Bnode<ItemType>* root, ItemType entry);//XXX

     /**
  * @post none
  * @param none
  * @return T for entry
  */
  Bnode<ItemType>* removeHelper(ItemType key, Bnode<ItemType>* root);

  //For the following methods, each method will take a function as a parameter
  //These function then call the provided function on every entry in the tree in the appropriate order (i.e. pre, in, post)
  //The function you pass in will need to a static method

     /**
ALL VISIT METHODS: Take a parameter of a static function for what happens when it visits.
They traverse the tree and perform the visit in a certain order. Other parameter simply helps keep track
of the traversal.
  */

  void visitPreOrder(void visit(ItemType)) const; //Visits each node in pre order
  void visitInOrder(void visit(ItemType)) const; //Visits each node in in order
  void visitPostOrder(void visit(ItemType)) const;
  //helper
  void visitPreOrderHelper(Bnode<ItemType>* temp, void visit(ItemType)) const; //Visits each node in pre order
  void visitInOrderHelper(Bnode<ItemType>* temp, void visit(ItemType)) const; //Visits each node in in order
  void visitPostOrderHelper(Bnode<ItemType>* temp, void visit(ItemType)) const; //Visits each no

};
#include "BinarySearchTree.cpp"
#endif
