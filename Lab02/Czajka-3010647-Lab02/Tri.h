/**
@Author: Tony Czajka 3010647
@File:Tri.h
@Date: 9/16/2021
@Brief:This is the header file for the Tri class, it defines all the methods
and variables for the Tri class.
**/
#ifndef TRI_H
#define TRI_H
#include "Shape.h"
#include <string>

class Tri : public Shape
{
private:
	double m_base;
	double m_height;
public:
	Tri(double tempBase, double tempHeight);
	double area()const;
	std::string shapeName()const;
	~Tri();
};
#endif
