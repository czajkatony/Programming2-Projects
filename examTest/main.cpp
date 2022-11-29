/**
@Author: Tony Czajka 3010647
@File: main.cpp
@Date: 10/19/21
@Brief:This is the main.cpp class. It implements the Executive class to take in an
       input.txt file and execute a program that mimics a web browser.
**/
#include <iostream>
#include <stdexcept>

#include "LinkedList.h"

int main() {
	try{
	LinkedList<char>* list=new LinkedList<char>();
	list->insert(0,'a');
	list->insert(1,'b');
	list->insert(2,'c');
	list->insert(3,'d');
	list->insert(4,'e');
///**
		std::cout<<"Original List:\n";
	for(int i=0; i<5;i++){

		std::cout<<list->getEntry(i)<<'\n';
	}
//**/
//**
	list->reverse();
			std::cout<<"Reversed List:\n";
	for(int i=0; i<5;i++){

		std::cout<<list->getEntry(i)<<'\n';
	}
///**/
	}
	catch(std::runtime_error& e){
		std::cout<<"ERROR: "<<e.what()<<'\n';
	}

  return 0;
}
