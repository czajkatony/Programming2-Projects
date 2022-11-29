/**
@Author: Tony Czajka 3010647
@File: Executive.cpp
@Date: 12/1/2021
@Brief:Implements the methods of the Binary node class
**/

#include "Executive.h"

Executive::Executive(std::string FileName){
	editPokedex=new BinarySearchTree<Pokemon, int>();
	copyPokedex=new BinarySearchTree<Pokemon, int>();
	originalPokedex=editPokedex;
	userChoice=0;
	copyBool=false;
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
			editPokedex->add(temp);
		}
	}
	else{
		throw(std::runtime_error("Invalid Filename given!\n"));
	}
	inFile.close();
}

Executive::~Executive(){
	delete originalPokedex;
	delete copyPokedex;
}

void Executive::pokemonPrinter(Pokemon p){
	std::cout<<"Pokedex ID#: "<<p.getPokedex()<<" | American Name: "<<p.getAmerican()<<" | Japanese Name: "<<p.getJapanese()<<'\n';
}

void Executive::run(){
	while(userChoice!=6){
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
		else if(userChoice==4){
			copy();
			std::cout<<'\n'<<'\n';
		}
		else if(userChoice==5){
			remove();
		}
		else if(userChoice!=6){
			std::cout<<"Invalid option selected. Please try again.\n";
		}
	}
}

void Executive::printMenu(){
	std::cout<<"Welcome to the Pokedex Menu!\n"<<"1) Search\n"<<"2) Add\n"<<"3) Print\n"
	<<"4) Copy Pokedex\n"<<"5) Remove Pokemon\n"<<"6) Exit\n"<<"Enter menu selection: ";

}

void Executive::search(){
	try{
		int userID;
		std::cout<<'\n'<<'\n';
		std::cout<<"Please enter the ID of the pokemon you would like to search for: ";
		std::cin>>userID;
		std::cout<<'\n'<<'\n';
		pokemonPrinter(editPokedex->search(userID));
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
		editPokedex->add(temp);
	}
	catch(std::runtime_error& e){
		std::cout<<"ERROR: "<<e.what()<<'\n';
	}
}

void Executive::print(){
	BinarySearchTree<Pokemon, int>* printChoice=originalPokedex;
	if(copyBool){
		int userChoice=0;
		while(userChoice!=1&&userChoice!=2){
			std::cout<<"Would you like to print 1) Original Pokedex or 2) Copied Pokedex?: ";
			std::cin>>userChoice;
			if(userChoice==2){
				printChoice=copyPokedex;
			}
			else if(userChoice!=1){
				std::cout<<"Invalid option selected please try again.\n";
			}
		}
	}
	int userTraversal=0;
	while(userTraversal!=1 && userTraversal!=2 && userTraversal!=3){
		std::cout<<'\n'<<'\n';
		std::cout<<"Entire Pokedex will be printed. In which traversal order would you like to see?\n";
		std::cout<<"1) Pre-Order\n"<<"2) In-Order\n"<<"3) Post-Order\n"<<"(Enter number): ";
		std::cin>>userTraversal;
		std::cout<<'\n'<<'\n';
		if(userTraversal==1){
			printChoice->visitPreOrder(pokemonPrinter);
		}
		else if(userTraversal==2){
			printChoice->visitInOrder(pokemonPrinter);
		}
		else if(userTraversal==3){
			printChoice->visitPostOrder(pokemonPrinter);
		}
		else{
			std::cout<<"Invalid option selected, please try again.\n";
		}
	}
}

void Executive::copy(){
	if(copyBool==false){
		Bnode<Pokemon>* newRootA=originalPokedex->copyTree();
		copyPokedex->setRoot(newRootA);
		copyBool=true;
		int editChoice=0;
		while(editChoice!=1&&editChoice!=2){
			std::cout<<"Would you like to edit the original Pokedex or the copied Pokedex from here on out?\n"<<
			"1) Original Pokedex\n"<<"2) Copied Pokedex\n"<<"Enter choice: ";
			std::cin>>editChoice;
			if(editChoice==2){
				editPokedex=copyPokedex;
			}
			else if(editChoice!=1){
				std::cout<<"Invalid Choice entered please try again!\n"<<'\n';
			}
		}
	}
	else{
		std::cout<<"Pokedex can only be copied once.\n";
	}
}

void Executive::remove(){
	try{
		int userChoice;
		std::cout<<"Please enter the ID nubmer of the pokemon you would like to remove: ";
		std::cin>>userChoice;
		editPokedex->remove(userChoice);
	}
	catch(std::runtime_error& e){
		std::cout<<"ERROR: "<<e.what()<<'\n';
	}
}
