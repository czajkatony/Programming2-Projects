/**
author: Tony Czajka 3010647
file: Executive.cpp
assigment: Lab01
date: September 15, 2021
brief: This file implements the member methods of the Executive class which were defined in
		Executive.h.
**/
#include "Executive.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>

/*
NOTES: Got the functions set up into the if statements
Next steps: Write the code for the individual functions that takes input and uses
variables from the boardgame class to print out the desired result to user.
Also, check the parameters in Executive.h cause I don't need those. Also, edit
make file and check for errors in all files
Also, destructors will be difficult to do.
*/

//constructor gets all the data and puts it into an array, creating
//a board game class object for each game and puts those into an array
Executive::Executive(std::string fileName){

    int tempCount=0;
    std::ifstream inFile;
    inFile.open(fileName);
    inFile>>tempCount;
    count=tempCount;
	allGames= nullptr;
    allGames=new BoardGame*[count];
    for(int i=0; i<count; i++)
    {
      std::string tempName;
      double tempGR;
      double tempPR;
      int tempYear;
      int tempMP;
      int tempMT;
      inFile>>tempName>>tempGR>>tempPR>>tempYear>>tempMP>>tempMT;
      newGame = new BoardGame (tempName, tempGR, tempPR,tempYear,tempMP,tempMT);
      allGames[i]=newGame;


    }
	run(allGames);
	///**

	//**/
    inFile.close();


}//ends constructor
Executive::~Executive(){ //destructor
  for(int i=0;i<count;i++)
	{

		delete allGames[i] ;
		//std::cout<<allGames[i]->getName()<<'\n';

	}
  delete[] allGames;
}
//prints menu and asks for selection
int Executive::print()
{
  int userSelection=0;
  do{
  std::cout<<"Please choose an option from the menu below\n";
  std::cout<<"1) Print all games\n";
  std::cout<<"2) Print all games from a year\n";
  std::cout<<"3) Print a ranking range\n";
  std::cout<<"4) The People VS Dr. Gibbons\n";
  std::cout<<"5) Print based on play time \n";
  std::cout<<"6) Exit the program\n";
  std::cin>>userSelection;
  while(std::cin.fail())
  {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout<<"Sorry, your input did not seem to be an int between 1-6. Try again: ";
		std::cin>>userSelection;
  }
  if(userSelection>6||userSelection<1)
  {
  std::cout<<"Please re-enter a valid input\n";
  }
  }while(userSelection>6 || userSelection<1);
  return(userSelection);
}//End print function

//==============================================================================
//run function, handles the selection from the menu
void Executive::run(BoardGame** allGames) {
bool exit=false;
do{

int userSelection=print();
//-------------------------------------------------------------
if(userSelection==1)
{
pAll(allGames);
std::cout<<'\n';
}
//-------------------------------------------------------------
if(userSelection==2)
{
   pYear(allGames);
}
//-------------------------------------------------------------
if(userSelection==3)
{
pRanking(allGames);
}
//-------------------------------------------------------------
if(userSelection==4)
{
pVSg(allGames);
}
//-------------------------------------------------------------
if(userSelection==5)
{
pT(allGames);
}
//-------------------------------------------------------------
if(userSelection==6)
{
exit=true;
}
//-------------------------------------------------------------
}while(exit==false);
}//End of Run function
//======================================================================

//print all function
void Executive::pAll(BoardGame** allGames) const
{
  for(int i=0; i<count; i++)
  {
    std::cout<<allGames[i]->getName()<<"("<<allGames[i]->getYear()<<")"<<"[GR="<<allGames[i]->getGR()<<", PR="<<allGames[i]->getPR()
	<<", MP="<<allGames[i]->getMP()<<", MT="<<allGames[i]->getMT()<<"]\n";
  }
}
//print based on year functions
void Executive::pYear(BoardGame** allGames)
  {
	  int year=0;
	  std::cout<<"Please enter a year to search games from that year. ";
	  std::cin>>year;
	  while(std::cin.fail())
	  {
		  std::cin.clear();
		  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		  std::cout<<"Sorry, your input did not seem to be an int. Try again: ";
		  std::cin>>year;
	  }
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	  bool noGamesFound= true;
	  std::cout<<"The following is a list of games from "<<year<<".\n";
		for(int i=0; i<count; i++)
		{
			if(allGames[i]->getYear()==year)
			{
				std::cout<<allGames[i]->getName()<<'\n';
				noGamesFound=false;
			}
		}
		if(noGamesFound==true)
		{
			std::cout<<"No games found\n";
		}

  }
//print ranking functions
void Executive::pRanking(BoardGame** allGames)
{
	double rMin=0;
	double rMax=0;
	std::cout<<"Please enter a range of rankings to list all games that fall between said ranking.\n";
	do{
	std::cout<<"Enter minimum ranking: ";
	std::cin>>rMin;
    while(std::cin.fail())
	  {
		  std::cin.clear();
		  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		  std::cout<<"Sorry, your input did not seem to be an double. Try again: ";
		  std::cin>>rMin;
	  }

	std::cout<<"Please enter maximum ranking: ";
	std::cin>>rMax;
	    while(std::cin.fail())
	  {
		  std::cin.clear();
		  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		  std::cout<<"Sorry, your input did not seem to be an double. Try again: ";
		  std::cin>>rMax;
	  }
	  if(rMin>rMax)
	  {
		  std::cout<<"Minimum ranking cannot be higher than Maximum ranking, please try again.\n";
	  }
	}while(rMin>rMax);
	std::cout<<"The following is a list of games rated between "<<rMin<<" and "<<rMax<<".\n";
	bool noGamesFound=true;
	for(int i=0; i<count; i++)
	{
		if(allGames[i]->getGR()>rMin && allGames[i]->getGR()<rMax)
		{
			std::cout<<allGames[i]->getName()<<'\n';
			noGamesFound=false;
		}
	}
	if(noGamesFound==true)
	{
		std::cout<<"No Games found within the range of ratings.\n";
	}
}
//people vs gibbons functions
void Executive::pVSg(BoardGame** allGames)
{
	//obtain the range rom the user
	double range=0;
	do{
	std::cout<<"Please enter a number 0-10 (decimals allowed) to see which games Dr. Gibbons rating is different than the peoples value by that number or higher: ";
	std::cin>>range;
	while(std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout<<"Sorry, your input did not seem to be an double. Try again: ";
		std::cin>>range;
	}
	}while(range>10||range<0);

	std::cout<<"The following is a list of games where Dr. Gibbons and the people disagreed by "<<range<<" or more.\n";
	bool noGamesFound=true;
	for(int i=0; i<count; i++)
	{
		if(std::abs(allGames[i]->getGR()-allGames[i]->getPR())>=range)
		{
			std::cout<<allGames[i]->getName()<<'\n';
			noGamesFound=false;
		}
	}
	if(noGamesFound==true)
	{
		std::cout<<"No Games found with this difference between ratings (or higher).\n";
	}
}
//play time functions
void Executive::pT(BoardGame** allGames)
{
	//obtain the play time from user
	int time=0;
	do{
	std::cout<<"Please enter an integer (in minutes and greater than 0) to see which games have a min play time of that value or lower: ";
	std::cin>>time;
	while(std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout<<"Sorry, your input did not seem to be an int. Try again: ";
		std::cin>>time;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}while(time<=0);

	std::cout<<"The following is a list of games with a min play time of "<<time<<" or less.\n";
	bool noGamesFound=true;
	for(int i=0; i<count; i++)
	{
		if(allGames[i]->getMT()<=time)
		{
			std::cout<<allGames[i]->getName()<<'\n';
			noGamesFound=false;
		}
	}
	if(noGamesFound==true)
	{
		std::cout<<"No Games found with this min play time or lower\n";
	}
}
