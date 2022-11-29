/**
@Author: Tony Czajka 3010647
@File: main.cpp
@Date: 10/19/21
@Brief:This is the main.cpp class. It implements the Executive class to take in an
       input.txt file and execute a program that mimics a web browser.
**/
#include <iostream>
#include <stdexcept>

#include "Executive.h"

int main(int argc, char *argv[]) {
  try{
	  Executive* exec=new Executive(argv[1]);
	  exec->run();
	  delete exec;
   }
  catch(std::runtime_error& e){
    std::cout<<"Exception thrown. "<<e.what()<<'\n';
  }



  return 0;
}
