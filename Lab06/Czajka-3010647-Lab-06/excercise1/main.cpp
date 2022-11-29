/**
@Author: Tony Czajka 3010647
@File: Main.cpp (EXERCISE 1)
@Date: 10/21/21
@Brief:This is the main.cpp file for Exercise 1, it takes in a string of parenthasis
       from the user and checks if its balanced or not using recursion.
**/
#include <iostream>
#include <stdexcept>
#include <string>

/**
* @pre Needs valid input string from user.
* @post temp string is edited based on the characters in the input string.
* @param input string, index, and temp string. the Input string is the user's string
         the index keeps track of where in the string is being checked, and temp is
         what keeps track if the string is balanced or not. Parenthasis are added and
         removed from temp accordingly.
* @throw std::runtime_error if the user inputs a character thas not '(' or ')'
*@return true or false based on if the sequence is balanced or not.
*/
bool balCheck(std::string input, int index, std::string temp){
  if(index==input.size()){
    if(temp.length()==0){
      return(true);
    }
    if(temp.length()!=0){
      return(false);
    }
  }

  else if(input[index]=='('){
    temp+=input[index];
    return(balCheck(input,index+1,temp));
  }


  else if(input[index]==')'){
    if(temp.length()!=0){
      int deleteIndex=temp.find('(');
      temp.erase(deleteIndex,1);
      return(balCheck(input,index+1,temp));
    }
    else{
      return(false);
    }
  }
  else{
    throw(std::runtime_error("Invalid char placed in parenthasis sequence."));
  }


}
int main(int argc, char *argv[]){
try{
  std::string input=argv[1];
  std::string temp="";
  if(balCheck(input, 0,temp)){
    std::cout<<"The sequence "<<input<<" is balanced.\n";
  }
  else{
    std::cout<<"The sequence "<<input<<" is not balanced.\n";
  }
}
catch(std::runtime_error& e){
  std::cout<<"ERROR: "<<e.what()<<'\n';
}
}
