/**
@Author: Tony Czajka 3010647
@File: Executive.cpp
@Date: 10/6/21
@Brief: This is the .cpp file for the Executive class. This implements all the defined methods in order to receive instructions from an input file,
		and accordingly either fill the line, fill the elevator and empty the line, drop people off the elevator, or inspect the current status of the 
		line and elevator.
**/
#include "Executive.h"
Executive::Executive(std::string filename){
	m_filename=filename;
	elevator = new Stack<std::string>();
	line = new Queue<std::string>();
}
Executive::~Executive(){
	delete elevator;
	delete line;
}
void Executive::run(){
	std::fstream inFile;
	inFile.open(m_filename);
	while(inFile >> actionCode){
		if(actionCode=="WAIT"||actionCode=="PICK_UP" ||actionCode=="DROP_OFF" ||actionCode=="INSPECTION"){
			if(actionCode=="WAIT"){
				try{
					std::string name;
					inFile>>name;
					wait(name);
				}
				catch(std::runtime_error &e){
					std::cout<<"ERROR: "<<e.what()<<'\n';
				}
			}
			
			if(actionCode=="PICK_UP"){
				try{
					pickUp();
				}
				catch(std::runtime_error &e){
					std::cout<<"ERROR: "<<e.what()<<'\n';
				}
			}
			
			if(actionCode=="DROP_OFF"){
				try{
					int num;
					inFile>>num;
					dropOff(num);
				}
				catch(std::runtime_error &e){
					std::cout<<"ERROR: "<<e.what()<<'\n';
				}
			}
			
			if(actionCode=="INSPECTION"){
				try{
					inspection();
				}
				catch(std::runtime_error &e){
					std::cout<<"ERROR: "<<e.what()<<'\n';
				}
			}
			
		}
		else{
			throw(std::runtime_error("Invalid Action Code received from input file."));
		}
	}
}

void Executive::wait(std::string name){
		line->enqueue(name);
}

void Executive::pickUp(){
	if(!line->isEmpty()){
	try{
		int iterations=7-(elevator->getLength());
		
		for(int i=0;i<iterations;i++){
			if(!line->isEmpty()){
				elevator->push(line->peekFront());
				line->dequeue();
			}
		}
	}
	catch(std::runtime_error& e){
		std::cout<<"ERROR: "<<e.what()<<'\n';
	}
	}
	else{
		throw(std::runtime_error("Pick up attempted with an empty line."));
	}
}

void Executive::dropOff(int num){
	if(num<=7 && num>=0){
		try{
			for(int i=0;i<num;i++){
				elevator->pop();
			}
		}
		catch(std::runtime_error& e){
			std::cout<<"ERROR: "<<e.what()<<'\n';
		}
	}
	else if(num>7 ||num <0){
		throw(std::runtime_error("Drop Off attempted with a number greater than elevator capacity or a number less than zero."));
	}
	else if(num>line->getLength()){
		throw(std::runtime_error("Drop off attempted at a greater number than amount of people currently in elevator."));
	}
}

void Executive::inspection()const{
	try{
		std::cout<<"Elevator status:\n";
		if(elevator->isEmpty()){
			std::cout<<"The elevator is empty.\n"<<"No one is in the elevator\n";
		}
		else{
			std::cout<<"The elevator is not empty.\n";
			std::cout<<elevator->peek()<<" will be the next person to leave the elevator.\n";
		}
		if(line->isEmpty()){
			std::cout<<"The line is empty.\n"<<'\n';
		}
		else{
			std::cout<<line->peekFront()<<" will be the next person to get on the elevator.\n"<<'\n';
		}

	}
	catch(std::runtime_error& e){
		std::cout<<"ERROR: "<<e.what()<<'\n';
	}
}
