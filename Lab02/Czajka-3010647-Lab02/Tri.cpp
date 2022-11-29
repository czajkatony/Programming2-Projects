/**
@Author: Tony Czajka 3010647
@File:Tri.cpp
@Date: 9/16/2021
@Brief:This file implements the member methods from the Tri class.
**/
#include "Tri.h"
#include<string>

/**
       * @pre Valid tempBase and tempheight values
       * @post Tri object is created
       * @param tempBase and tempHeight
       * @return nothing
       * @throw None
**/
Tri::Tri(double tempBase, double tempHeight)
{
m_base=tempBase;
m_height=tempHeight;
}

/**
       * @pre None
       * @post Const
       * @param None
       * @return Double, representing the area of a triangle
       * @throw None
**/
double Tri::area()const
{
return((0.5*m_base*m_height));
}

/**
       * @pre None
       * @post Const
       * @param none
       * @return string representing the name Triangle
       * @throw None
**/
std::string Tri::shapeName()const
{
return("Triangle");
}

Tri::~Tri(){}
