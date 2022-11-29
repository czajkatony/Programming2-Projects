/**
@Author: Tony Czajka 3010647
@File: Executive.cpp
@Date: 12/1/2021
@Brief:Implements the methods of the Binary node class
**/

#include "Executive.h"

Executive::Executive(std::string FileName){
	userChoice=0;
	std::fstream inFile;
	inFile.open(FileName);
	if(inFile.is_open()){
		std::string tempUS;
		std::string tempJP;
		int tempID;
		Pokemon temp;
		while(inFile >> tempUS >> tempID >> tempJP){
			temp.setAmerican(tempUS);
			temp.setJapanese(tempJP);
			temp.setPokedex(tempID);
			Pokedex.add(temp);
		}
	}
	else{
		throw(std::runtime_error("Invalid Filename given!\n"));
	}
	inFile.close();
}

void Executive::pokemonPrinter(Pokemon p){
	std::cout<<"Pokedex ID#: "<<p.getPokedex()<<" | American Name: "<<p.getAmerican()<<" | Japanese Name: "<<p.getJapanese()<<'\n';
}

void Executive::run(){
	while(userChoice!=4){
		printMenu();
		std::cin>>userChoice;
		if(userChoice==1){
			search();
			std::cout<<'\n'<<'\n';
		}
		else if(userChoice==2){
			add();
			std::cout<<'\n'<<'\n';
		}
		else if(userChoice==3){
			print();
			std::cout<<'\n'<<'\n';
		}
		else if(userChoice!=4){
			std::cout<<"Invalid option selected. Please try again.\n";
		}
	}
}

void Executive::printMenu(){
	std::cout<<"Welcome to the Pokedex Menu!\n"<<"1) Search\n"<<"2) Add\n"<<"3) Print\n"<<"4) Exit\n"<<"Enter menu selection: ";

}

void Executive::search(){
	try{
		int userID;
		std::cout<<'\n'<<'\n';
		std::cout<<"Please enter the ID of the pokemon you would like to search for: ";
		std::cin>>userID;
		std::cout<<'\n'<<'\n';
		pokemonPrinter(Pokedex.search(userID));
	}
	catch(std::runtime_error& e){
		std::cout<<"ERROR: "<<e.what()<<'\n';
	}
}

void Executive::add(){
	std::string userUS;
	std::string userJP;
	int userID;
	std::cout<<'\n'<<'\n';
	std::cout<<"Please enter the Pokemon's US name: ";
	std::cin>>userUS;
	std::cout<<"Please enter the Pokemon's Japanese name: ";
	std::cin>>userJP;
	std::cout<<"Please enter the Pokemon's Pokedex number: ";
	std::cin>>userID;
	Pokemon temp;
	temp.setAmerican(userUS);
	temp.setJapanese(userJP);
	temp.setPokedex(userID);
	std::cout<<'\n'<<'\n';
	try{
		Pokedex.add(temp);
	}
	catch(std::runtime_error& e){
		std::cout<<"ERROR: "<<e.what()<<'\n';
	}
}

void Executive::print(){
	int userTraversal=0;
	while(userTraversal!=1 && userTraversal!=2 && userTraversal!=3){
		std::cout<<'\n'<<'\n';
		std::cout<<"Entire Pokedex will be printed. In which traversal order would you like to see?\n";
		std::cout<<"1) Pre-Order\n"<<"2) In-Order\n"<<"3) Post-Order\n"<<"(Enter number): ";
		std::cin>>userTraversal;
		std::cout<<'\n'<<'\n';
		if(userTraversal==1){
			Pokedex.visitPreOrder(pokemonPrinter);
		}
		else if(userTraversal==2){
			Pokedex.visitInOrder(pokemonPrinter);
		}
		else if(userTraversal==3){
			Pokedex.visitPostOrder(pokemonPrinter);
		}
		else{
			std::cout<<"Invalid option selected, please try again.\n";
		}
	}
}

