/**
author: Tony Czajka 3010647
file: main.cpp
date: September 15, 2021
brief: This file utilizes the BoardGame and Executive classes to take a list of boardgames 
		from a file and present the user with an assortment of options on how to sort/view
		those board games.
**/
#include <iostream>
#include "BoardGame.h"
#include "Executive.h"

int main(int argc, char* argv[])
{
if(argc<2)
{
std::cout<<"Incorrect number of parameters!\n";
}
else
{
Executive exec(argv[1]);
//exec.run();
}
return(0);
}
