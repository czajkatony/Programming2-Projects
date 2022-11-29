/**
@Author: Tony Czajka 3010647
@File:Shape.h
@Date: 9/16/2021
@Brief:This is the interface class file.
**/
#ifndef SHAPE_H
#define SHAPE_H
#include <string>
class Shape
{
   public:
   virtual double area() const = 0;
   virtual std::string shapeName() const = 0;
   virtual ~Shape() {} //is this right??
};
#endif
