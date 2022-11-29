/**
@Author: Tony Czajka 3010647
@File: City.h
@Date: 10/29/21
@Brief:This is the header file for the City class. This outlines the member variables and methods needed to move
	   the blob around the city based on the designated rules.
**/

#ifndef CITY_H
#define CITY_H
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>

class City{
private:
  int rows;
  int cols;
  int m_start_x;
  int m_start_y;
  char** grid;
  char** sewerGrid;
  bool isSewer;
  int totalEaten;
public:
/**
@ Makes the City
@ param inFile, the file that inputs the city information.
**/
  City(std::ifstream& inFile);

/**
@ post: deltes the city
**/
  ~City();
  
 /**
@ Covers all applicable tiles with blobs (B)
@post the city array will be modified, all applicable tiles will go to B, also, the sewer Grid will be modified as well
	  to keep track of which sewers have been visited.
**/
  void blobbifyCity();

/**
@ Prints the city information
@post: Prints the city
**/
  void print();
/**
@ Blobbifies subsection of city, excluding sewers
@ param: and x and a y to signify which position will start to be blobbified.
@post: replaces all applicable tiles in a subsection of the city with B's
@post: Modifies isSewer to true and edits the sewerGrid if the current spot is a sewer.
**/
  void blobbify(int x, int y);

/**
@ Helper funciton to change array spot to a B
@ param: and x and a y representing which part of the city is blobbified.
@post: changes the city arrray to a 'B' at (x,y)
**/
  void mark(int x, int y);
/**
@ Helper function to see if a move is legal or not
@ returns a bool if the desired array position is a wall or not.
@ param: x and y position that represent the posiiton of the array that is being checked.
**/
  bool isValidMove(int x,int y);
  
 /**
@ return: returns an int that represents how many people got eaten so that this info can be printed in main.
**/
  int getPeopleEaten()const;




};
#endif
