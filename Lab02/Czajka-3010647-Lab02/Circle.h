/**
@Author: Tony Czajka 3010647
@File:Circle.h
@Date: 9/16/2021
@Brief:This is the header file for the Circle class.It defines all the variables
and member methods for the Circle class.
**/
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include <string>

class Circle : public Shape{
private:
  double m_radius;
public:
  Circle(double tempRadius);
  double area()const;
  std::string shapeName()const;
  ~Circle();
};
#endif
