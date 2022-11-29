/**
@Author: Tony Czajka 3010647
@File:Executive.h
@Date: 9/16/2021
@Brief:This is the header file for the Executive class, it defines and initializes
all the member variables and methods for the Executive class.
**/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <fstream>
#include <iostream>
#include "ShapeContainer.h"
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Tri.h"


class Executive{

private:
  std::string m_filename;
  int count;
  std::string actionCode;
  int index;
  std::string shapeCode;
  double data1;
  double data2;
  std::fstream inFile;


public:
  Executive(std::string filename);
  void run();
  ShapeContainer* container;
  Shape* shapePointer;
  ~Executive();


};
#endif
