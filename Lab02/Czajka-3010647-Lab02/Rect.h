/**
@Author: Tony Czajka 3010647
@File:Rect.h
@Date: 9/16/2021
@Brief:This is the header file for the Rect class which defines the variables
and member methods.
**/
#ifndef RECT_H
#define RECT_H
#include "Shape.h"
#include <string>

class Rect: public Shape
{
private:
  double m_length;
  double m_width;
public:
  Rect(double tempLength, double tempWidth);
  double area() const;
  std::string shapeName() const;
  ~Rect();

};
#endif
