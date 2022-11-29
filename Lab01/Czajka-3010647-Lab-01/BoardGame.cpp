/**
author: Tony Czajka 3010647
file: BoardGame.cpp
assigment: Lab01
date: September 15, 2021
brief: This file implements the member methods of the BoardGame class which were defined in
		BoardGame.h.
**/
#include "BoardGame.h"
#include <string>

BoardGame::BoardGame(std::string tempName, double tempGR, double tempPR, int tempYear, int tempMP, int tempMT){
  m_Name=tempName;
  m_GR=tempGR;
  m_PR=tempPR;
  m_Year=tempYear;
  m_MP=tempMP;
  m_MT=tempMT;
}
BoardGame::~BoardGame()
{

}
//Get name
std::string BoardGame::getName() const
{
return(m_Name);
}
//Get Gibbons Rating
double BoardGame::getGR() const
{
return(m_GR);
}
//Get Public Rating
double BoardGame::getPR() const
{
return(m_PR);
}
//Get Year
int BoardGame::getYear() const
{
return(m_Year);
}
//Get Min Players
int BoardGame::getMP() const
{
return(m_MP);
}
//Get Min Play Time
int BoardGame::getMT() const
{
return(m_MT);
}
