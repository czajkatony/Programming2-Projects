/**
author: Tony Czajka 3010647
file: Executive.h
assigment: Lab01
date: September 15, 2021
brief: This file is the header file for the Executive class, it defines all the methods of
		the Executive class that are implemented in Executive.cpp.
**/
#include "BoardGame.h"
#include <string>

class Executive
{
private:
  int count;

public:
  BoardGame** allGames;
  BoardGame* newGame; //maybe
//Executive class constructor
  Executive (std::string fileName);
  int choice;
  int year;
  int rMin;
  int rMax;

/**
run
pre: Needs to be associated with the executive class object, needs a proper BoardGame** parameter
	 passed in.
post: can edit the "bool exit" variable which controls the exiting of the program
param: BoardGame pointer to an array of BoardGame pointers called allGames
throw:none
return: none
**/
  void run(BoardGame** allGames); //userchoice

/**
printassigment: Lab01
pre: Needs to be associated with the executive class object
post: can edit the user selection variable which indicates their choice of menu functions
param: none
throw:none
return: int userSelection which is used to identify which function user wants to run.
**/
  int print();

/**
pAll
pre: Needs to be associated with the executive class object, needs a proper BoardGame** parameter
	 passed in.
post: Doesn't affect anything in program, simply prints a list of names to terminal
param: BoardGame pointer to an array of BoardGame pointers called allGames
throw:none
return: none
**/
  void pAll(BoardGame** allGames) const;

/**
pYear
pre: Needs to be associated with the executive class object, needs a proper BoardGame** parameter
	 passed in.
post: Bool for if no games are found can be changed, other than that, it only prints names of games
	  from a certain year or displays an error message.
param: BoardGame pointer to an array of BoardGame pointers called allGames
throw:none
return: none
**/
  void pYear(BoardGame** allGames);//take out the parameters

/**
pRanking
pre: Needs to be associated with the executive class object, needs a proper BoardGame** parameter
	 passed in.
post: Max and Min values are entered by user so these are changed, also has a bool for if games within
	  range are found or not. Other than this no Board Game objects are changed.
param: BoardGame pointer to an array of BoardGame pointers called allGames
throw:none
return: none
**/
  void pRanking(BoardGame** allGames);

/**
pVSg
pre: Needs to be associated with the executive class object, needs a proper BoardGame** parameter
	 passed in.
post: takes range of disagreement from user which needs to be edited, other than this it does not change
	  any of the BoardGame objects or major data values.
param: BoardGame pointer to an array of BoardGame pointers called allGames
throw:none
return: none
**/
  void pVSg(BoardGame** allGames);

 /**
pT
pre: Needs to be associated with the executive class object, needs a proper BoardGame** parameter
	 passed in.
post: has bool variable to determine if error message needs to be printed or not, otherwise, nothing is
	  edited including no BoardGame objects or pointers.
param: BoardGame pointer to an array of BoardGame pointers called allGames
throw:none
return: none
**/
  void pT(BoardGame** allGames);

 //Executive class destructor
  ~Executive();
};
