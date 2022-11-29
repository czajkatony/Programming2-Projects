/**
@Author: Tony Czajka 3010647
@File: Pokemon.cpp
@Date: 12/1/2021
@Brief:Pokemon.cpp | Implements the methods of the Pokemon class
**/
#include "Pokemon.h"

Pokemon::Pokemon(){
  m_PokedexNumber=0;
  m_AmericanName="";
  m_JapaneseName="";
}
void Pokemon::setPokedex(int temp){
  m_PokedexNumber=temp;
}
void Pokemon::setAmerican(std::string temp){
  m_AmericanName=temp;
}
void Pokemon::setJapanese(std::string temp){
  m_JapaneseName=temp;
}
int Pokemon::getPokedex()const{
  return(m_PokedexNumber);
}
std::string Pokemon::getAmerican()const{
  return(m_AmericanName);
}
std::string Pokemon::getJapanese()const{
  return(m_JapaneseName);
}
//Operator overloading with other Pokemon
bool Pokemon::operator==(const Pokemon& right)const{
  return(this->getPokedex()==right.getPokedex());
}
bool Pokemon::operator<(const Pokemon& right)const{
  return(this->getPokedex()<right.getPokedex());
}
bool Pokemon::operator>(const Pokemon& right)const{
  return(this->getPokedex()>right.getPokedex());
}
//with ID ints
bool Pokemon::operator==(int id)const{
  return(this->getPokedex()==id);
}
bool Pokemon::operator<(int id)const{
  return(this->getPokedex()<id);
}
bool Pokemon::operator>(int id)const{
  return(this->getPokedex()>id);
}
