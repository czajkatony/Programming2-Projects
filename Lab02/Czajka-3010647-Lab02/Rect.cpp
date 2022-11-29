/**
@Author: Tony Czajka 3010647
@File: Rect.cpp
@Date: 9/16/2021
@Brief:This file implements the member methods for the Rectangle class
**/
#include "Rect.h"
#include <string>

/**
       * @pre None
       * @post Rect object is createdd
       * @param tempLength and tempWidth
       * @return nothing
       * @throw None
**/
Rect::Rect(double tempLength, double tempWidth)
{
    m_length=tempLength;
    m_width=tempWidth;
}

/**
       * @pre None
       * @post Const
       * @param None
       * @return Double, representing the area of a rectangle
       * @throw None
**/
double Rect::area()const
{
  return(m_length*m_width);
}

/**
       * @pre None
       * @post Const
       * @param None
       * @return String with the name of the shape
       * @throw None
**/
std::string Rect::shapeName() const
{
  return("Rectangle");
}

Rect::~Rect(){}
