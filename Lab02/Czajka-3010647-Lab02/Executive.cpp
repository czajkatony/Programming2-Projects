/**
@Author: Tony Czajka 3010647
@File:Executive.cpp
@Date: 9/16/2021
@Brief:This file implements the member methods from the Executive class. It
@contains all the main functions of the program.
**/
#include <fstream>
#include <string>
#include <iostream>
#include "Executive.h"
//#include "ShapeContainer.h"
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Tri.h"

/**
       * @pre Valid filename
       * @post Executive object created, inFile created and opened,
			 New shapeContainer created named container
       * @param std::string filename
       * @return none
       * @throw None
**/
Executive::Executive(std::string filename)
{
m_filename=filename;
inFile.open(filename);
inFile>>count;
container=nullptr;
container=new ShapeContainer(count);
inFile.close();

}

/**
       * @pre Executive object must have been created
       * @post Shape container is deleted
       * @param none
       * @return none
       * @throw None
**/
Executive::~Executive()
{
	delete shapePointer;
	//	delete container;
	//	std::cout<<"container deleted\n";
	//inFile.close();
}

/**
       * @pre Must have valid Executive object
       * @post Many options, shapes can be added to the container, deleted,
			 have their info printed to terminal, or the mehtod exited.
       * @param none
       * @return none
       * @throw an std::runtime_error exception for each action that cannot take place
**/
void Executive::run()
{
	bool exit=false;
	inFile.open(m_filename);
	int count=0;
	inFile>>count;
	do{
	//while(exit==false){
	inFile>>actionCode>>index;
	//std::cout<<actionCode<<" : "<<index<<'\n';
	//std::cout<<"The m_size is: "<<m_size<<'\n';

	                                                                           //    /**
	//std::cout<<actionCode<<" : "<<index<<" : "<<shapeCode<<" : "<<data1<<" : "<<data2<<'\n';
	if(actionCode=="ADD")
	{
		try{
		inFile>>shapeCode;
		shapePointer=nullptr;
		if(shapeCode=="CIR")
		{
			inFile>>data1;

			shapePointer= new Circle(data1);
			container->add(shapePointer, index);
			//delete circlePointer;
		}
		if(shapeCode=="TRI")
		{
			inFile>>data1;
			inFile>>data2;
			shapePointer= new Tri(data1,data2);
			container->add(shapePointer, index);
		//	delete trianglePointer;
		}
		if(shapeCode=="REC")
		{
			inFile>>data1;
			inFile>>data2;

			shapePointer= new Rect(data1,data2);
			container->add(shapePointer, index);
		//	delete rectanglePointer;
		}
		}
		catch(std::runtime_error& e)
		{
			std::cout<<"Could not add.\n"<<e.what()<<'\n';
			delete shapePointer;
		}
	}
	                                                           //   **/
	if(actionCode=="DELETE") //NEEDS EXCEPTION
	{

		//std::cout<<"Delete object recognized"<<index<<'\n';
		try{
			container->remove(index);
		}
		catch(std::runtime_error& e)
		{
			std::cout<<"Could not Delete.\n"<<e.what()<<'\n';
		}
	}//throw
	if(actionCode=="PRINT") //NEEDS EXCEPTION
	{
		try{
			std::cout<<"Shape at index "<<index<<": "<<container->shapeName(index)<<" area = "
			<<container->area(index)<<" units squared.\n";
		}
		catch(std::runtime_error& e)
		{
			std::cout<<"Does not exist\n"<<e.what()<<'\n';
		}
	}//throw
	if(actionCode=="EXIT")
	{
		std::cout<<"Exiting...\n";
		exit=true;
	}
	/**
	actionCode="";
	index=0;
	shapeCode="";
	data1=0;
	data2=0;
	**/
	//}

	}while(exit==false);
	inFile.close();
	delete container;

}
