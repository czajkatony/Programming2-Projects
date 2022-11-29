/**
@Author: Tony Czajka 3010647
@File: Executive.h
@Date: 12/1/2021
@Brief: Defines the member methods and variables for the class.
**/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <fstream>
#include "Pokemon.h"
#include "BinarySearchTree.h"
class Executive{
private:
  int userChoice;
  bool copyBool;
  BinarySearchTree<Pokemon, int>* copyPokedex;
  BinarySearchTree<Pokemon, int>* editPokedex;
  BinarySearchTree<Pokemon, int>* originalPokedex;
  
    /**
  * @post prints the menu text
  * @param none
  * @return none
  */
  void printMenu();

    /**
  * @post prints results of the search
  * @param none
  * @return none
  */
  void search();
  
     /**
  * @post adds user define pokemon to the tree
  * @param none
  * @return none
  */ 
  void add();

    /**
  * @post prints out entire pokedex in user defined order
  * @param none
  * @return none
  */
  void print();
public:
  Executive(std::string FileName);
  ~Executive();
  



/**
  * @post prints pokemon information
  * @param none
  * @return none
  */
  static void pokemonPrinter(Pokemon p);
  
/**
  * @post puts everything together and calls the needed funcitons, handles user menu input.
  * @param none
  * @return none
  */
  void run();
  
  
  /**
  * @post copies the current pokedex into a copy pokedex
  * @param none
  * @return none
  */
  void copy();
  
  /**
  * @post contains all the menus and calls needed to remove an item from the okedex.
  * @param none
  * @return none
  */
  void remove();

  
};
#endif
