/**
@Author: Tony Czajka 3010647
@File:ShapeContainer.cpp
@Date: 9/16/2021
@Brief:This file implements the member methods of the ShapeContainer class.
**/
#include "ShapeContainer.h"
#include <iostream>
/**
       * @pre none
       * @post Shape Container object created
       * @param size
       * @return none
       * @throw
**/
ShapeContainer::ShapeContainer(int size)
{
	m_size= size;
  m_arrayOfShapes=new Shape*[m_size];
  for(int i=0; i<m_size; i++)
  {
    m_arrayOfShapes[i]=nullptr;
  }
}

ShapeContainer::~ShapeContainer()
{
	for(int i=0;i<m_size;i++)
	{
		m_arrayOfShapes[i]=  nullptr;

	}
	delete [] m_arrayOfShapes;


}

double ShapeContainer::area(int index) const
{
	if(index<m_size && index>=0&&m_arrayOfShapes[index]!=nullptr){
		return(m_arrayOfShapes[index]->area());
	}
	else if(m_arrayOfShapes[index]==nullptr){
		throw(std::runtime_error("ERROR: No shape object here\n"));
	}
	else{
		throw(std::runtime_error("ERROR: Index doesn't exist\n"));
	}
}

std::string ShapeContainer::shapeName(int index) const
{
	if(index<m_size && index>=0 &&m_arrayOfShapes[index]!=nullptr){
		return(m_arrayOfShapes[index]->shapeName());
	}
	else if(m_arrayOfShapes[index]==nullptr){
		throw(std::runtime_error("ERROR: No shape object here\n"));
	}
	else{
		throw(std::runtime_error("ERROR: Index doesn't exist\n"));
	}
}

void ShapeContainer::add(Shape* shapePtr, int index)
{
	if(index<m_size&&index>=0){
		m_arrayOfShapes[index]=shapePtr;
	}
	else{
		throw(std::runtime_error("ERROR: Index doesn't exist\n"));
	}
}

void ShapeContainer::remove(int index)
{
	if(index<m_size && index>=0 && m_arrayOfShapes[index]!=nullptr){
//std::cout<<"remove function index: "<<index<<'\n';
		m_arrayOfShapes[index]=nullptr;
  	if(m_arrayOfShapes[index]==nullptr)
		{
			std::cout<<"Successfully deleted\n";
		}
	}
	else{
		throw(std::runtime_error("ERROR: Index doesn't exist\n"));
	}
}
