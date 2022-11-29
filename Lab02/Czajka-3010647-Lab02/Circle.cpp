/**
@Author: Tony Czajka 3010647
@File:Circle.cpp
@Date: 9/16/2021
@Brief:This file implementes the member methods from the Circle class.
**/
#include "Circle.h"
#include <math.h>
#include <string>
#include <iostream>

/**
       * @pre Valid parameter tempRadius
       * @post Circle object is created
       * @param tempRadius
       * @return nothing
       * @throw None
**/
Circle::Circle(double tempRadius)
{
  m_radius=tempRadius;
}

/**
       * @pre None
       * @post Const
       * @param none
       * @return area representing the Circle area
       * @throw None
**/
double Circle::area()const
{
  return(m_radius*m_radius*3.14);
}

/**
       * @pre None
       * @post Const
       * @param none
       * @return string representing the shape name Circle
       * @throw None
**/
std::string Circle::shapeName() const
{
  return("Circle");
}

Circle::~Circle(){}
