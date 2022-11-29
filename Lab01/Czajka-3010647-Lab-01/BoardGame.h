/**
author: Tony Czajka 3010647
file: BoardGame.h
assigment: Lab01
date: September 15, 2021
brief: This file is the header file for the BoardGame class, it defines all the methods of
		the BoardGame class that are implemented in BoardGame.cpp.
**/
#ifndef BOARDGAME_H
#define BOARDGAME_H
#include <string>

class BoardGame{
private:
  std::string m_Name;
  double m_GR;//GibbRating
  double m_PR;//pubRating
  int m_Year;
  int m_MP; //minPlayers
  int m_MT; //minTime


public:

//BoardGame class constructor
    BoardGame(std::string tempName, double tempGR, double tempPR, int tempYear, int tempMP, int tempMT );
//get functions
/**
getName
pre: ran with a BoardGame object that has a value for m_Name
post: constant, does not modify
param: none
throw:none
return: string value for the name of the BoardGame
**/
  std::string getName() const;

 /**
getGR
pre: ran with a BoardGame object that has a value for m_GR
post: constant, does not modify
param: none
throw:none
return: the double value for professor gibbons rating of the board game
**/
  double getGR() const;

 /**
getPr
pre: ran with a BoardGame object that has a value for m_PR
post: constant, does not modify
param: none
throw:none
return: double value representing the peoples rating of the game
**/
  double getPR() const;

 /**
getYear
pre: ran with a BoardGame object that has a value for m_Year
post: constant, does not modify
param: none
throw:none
return: int value representing the year the game was made
**/
  int getYear()const;

/**
getMP
pre: ran with a BoardGame object that has a value for m_MP
post: constant, does not modify
param: none
throw:none
return: int value for minimum players needed to play the game
**/
  int getMP()const;

/**
getMT
pre: ran with a BoardGame object that has a value for m_MT
post: constant, does not modify
param: none
throw:none
return: int value representing the minimum time required to play the game.
**/
  int getMT()const;

//BoardGame class destructor
  ~BoardGame();
};
# endif
