/**
@Author: Tony Czajka 3010647
@File: Main.cpp
@Date: 10/29/21
@Brief:This is the main.cpp file for the blob excercise, it takes in the input file from the user
	   and executes the program using the City class.
**/

#include "City.h"


int main(int argc, char *argv[]){
  if(argc !=2){
    std::cout<<"Invalid number of parameters\n";
    return(0);
  }
  std::string filename=argv[1];
  std::ifstream inFile;
try{
  inFile.open(filename);
  if(inFile.is_open()){
    City c(inFile);
    c.print();
    c.blobbifyCity();
    c.print();
	std::cout<<"Total eaten: "<<c.getPeopleEaten()<<'\n'<<'\n';
  }
  else{
    std::cout<<"Invalid file.\n";
  }
}
catch(std::runtime_error& e){
	std::cout<<"ERROR: "<<e.what()<<'\n';
}
  return(0);
}
