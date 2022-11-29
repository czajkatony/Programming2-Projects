/**
@Author: Tony Czajka 3010647
@File: Pokemon.h
@Date: 12/1/2021
@Brief: Defines the member methods and variables for the class.
**/

#ifndef POKEMON_H
#define POKEMON_H
#include <string>
class Pokemon{
private:
  int m_PokedexNumber;
  std::string m_AmericanName;
  std::string m_JapaneseName;

public:
  Pokemon();

   /**
  * @post sets the Pokedex ID number
  * @param number for new ID
  */
  void setPokedex(int temp);

   /**
  * @post sets Americaan name
  * @param string for new name
  */
  void setAmerican(std::string temp);

   /**
  * @post m_japaneseName changed
  * @param string for new name
  */
  void setJapanese(std::string temp);

   /**
  * @return pokedex ID number
  */
  int getPokedex()const;
  std::string getAmerican()const;
  std::string getJapanese()const;

   /**
Operator overload
  */
  bool operator==(const Pokemon& right)const;

   /**
Operator overload
  */
  bool operator<(const Pokemon& right)const;
   /**
Operator overload
  */
  bool operator>(const Pokemon& right)const;
  //overload ID ints
   /**
Operator overload
  */
  bool operator==(int id)const;
  
   /**
Operator overload
  */
  bool operator<(int id)const;
  
   /**
Operator overload
  */
  bool operator>(int id)const;
};

#endif
