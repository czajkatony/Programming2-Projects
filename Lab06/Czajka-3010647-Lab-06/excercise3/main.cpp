/**
@Author: Tony Czajka 3010647
@File: Main.cpp (EXERCISE 3)
@Date: 10/21/21
@Brief:This is the main.cpp file for Exercise 3, it can either find the fibbonacci
			 number at any point in the sequence or check if a number is in the fibbonacci
			 sequence or not.
**/

#include <iostream>
#include <stdexcept>
#include <string>

/**
* @pre none
* @post none
* @param int n, this is the number for what place in the sequence you want to know
				 the number of.
* @throw std::runtime_error if an invalid sequence index is inputted.
* @return An int that represents the value of the number in the n spot of the sequence.
*/
int fib(int n){
	if(n==0){
		return(0);
	}
	else if(n==1){
		return(1);
	}
	else if(n>0){
		return(fib(n-1)+fib(n-2));
	}
	else{
		throw(std::runtime_error("Invalid 'ith' number of the sequence inputted."));
	}

}

/**
* @pre none
* @post None
* @param int n that represents what number user wants to check whether it is in the
			   sequence or not.
* @throw an std::runtime_error if the number is negative since there are no negative
				 numbers in the fibbonacci sequence.
* @return a bool representing whether or not the number is in the fibbonacci sequence or not.
*/
bool inFib(int n){
	int i=0;
	if(n<0){
		throw(std::runtime_error("There are no negative numbers in the Fibbonacci sequence, try again."));
	}
	while (fib(i)<=n){
		if(fib(i)==n){
			return(true);
		}
		i++;
	}
	return(false);
}

int main(int argc, char *argv[])
{
	try{
		std::string inputOption=argv[1];
		int userNum=std::stoi(argv[2]);
		if(inputOption=="-i"){

			std::cout<<"The fibbonacci number in the "<<userNum<<" spot is: "<<fib(userNum)<<'\n';
		}
		else if(inputOption=="-v"){
			if(inFib(userNum)){
				std::cout<<userNum<<" is in the sequence\n";
			}
			else{
				std::cout<<userNum<<" is not in the sequence\n";
			}
		}
		else{
			throw(std::runtime_error("Invalid choice passed by command line, please choose -i or -v."));
		}
	}
	catch(std::runtime_error& e){
		std::cout<<"ERROR: "<<e.what()<<'\n';
	}
}
