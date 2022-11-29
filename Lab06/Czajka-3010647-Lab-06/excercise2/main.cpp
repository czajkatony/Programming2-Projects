/**
@Author: Tony Czajka 3010647
@File: Main.cpp (EXERCISE 2)
@Date: 10/21/21
@Brief:This is the main.cpp file for Exercise 2, it takes a day from the user and
			 uses recursion to check how many people have the flu on that day.
**/
#include <iostream>
#include <stdexcept>

/**
* @pre user gives a valid day (int)
* @post none
* @param day for which the number of people with the flu is being analyzed
* @throw runtime_error if an invalid day is passed in (o or less)
* @return int representing how many people have the flu on that day.
*/
int recOutbreak(int day){
	if(day==1){
		return(1);
	}
	if(day==2){
		return(8);
	}
	if(day==3){
		return(22);
	}
	else if(day>0){
		return(recOutbreak(day-1)+recOutbreak(day-2)+recOutbreak(day-3));
	}
	else{
		throw(std::runtime_error("Invalid day entered."));
	}
}

int main()
{
	try{
		int userDay=0;
		std::cout<<"OUTBREAK!\n"<<"What day do you want a sick count for?: ";
		std::cin>>userDay;
		std::cout<<"Total people with the flu: "<<recOutbreak(userDay)<<'\n';
	}
	catch(std::runtime_error& e){
		std::cout<<"ERROR\n"<<e.what()<<'\n';
	}
}
