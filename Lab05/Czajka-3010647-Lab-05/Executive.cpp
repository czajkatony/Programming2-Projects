/**
@Author: Tony Czajka 3010647
@File: Executive.cpp
@Date: 10/19/21
@Brief:This is the implementation of the Executive class. This takes the Linked List
			 class and the Browser class and implements them to create a program that mimics
			 a web browser.
**/
#include "Executive.h"


Executive::Executive(std::string filename){
	m_filename=filename;
	browser=new Browser<std::string>();
	actionCode="";
}
Executive::~Executive(){
	delete browser;
}

void Executive::run(){
	std::fstream inFile;
	inFile.open(m_filename);
	while(inFile>>actionCode){
		//std::cout<<actionCode<<'\n';                //herherhehrhe
		if(actionCode=="NAVIGATE"){
			std::string url;
			inFile>>url;
	//		std::cout<<url<<" <-- URL input"<<'\n';                         ///asdfasdfasdf
			try{
				browser->navigateTo(url);
			}
			catch(std::runtime_error& e){
				std::cout<<"ERROR: "<<e.what()<<'\n'<<'\n';
			}

		}
		else if(actionCode=="BACK"){
			try{
				browser->back();
			}
			catch(std::runtime_error& e){
				std::cout<<"ERROR: "<<e.what()<<'\n'<<'\n';
			}
		}
		else if(actionCode=="FORWARD"){
			try{
				browser->forward();
			}
			catch(std::runtime_error& e){
				std::cout<<"ERROR: "<<e.what()<<'\n'<<'\n';
			}
		}
		else if(actionCode=="HISTORY"){
			try{
				LinkedList<std::string> printList;
				browser->copyCurrentHistory(printList);
					std::cout<<"Oldest\n"<<"===============\n";
				for(int i=printList.length()-1;i>=0;i--){
					if(printList.getEntry(i)==browser->current()){
						std::cout<<printList.getEntry(i)<<"  <== current\n";
					}
					else{
						std::cout<<printList.getEntry(i)<<'\n';
					}
				}
				std::cout<<"===============\n"<<"Newest\n"<<'\n';

			}
			catch(std::runtime_error& e){
				std::cout<<"ERROR: "<<e.what()<<'\n';
			}
		}
		else{
			throw(std::runtime_error("Invalid action code received from file."));
		}

	}
	inFile.close();
}
