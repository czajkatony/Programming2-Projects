LAB5: main.o Executive.o
	g++ -std=c++11 -g -Wall main.o Executive.o -o LAB5
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
Executive.o: Executive.h Executive.cpp Node.h Node.cpp Browser.h Browser.cpp BrowserHistoryInterface.h LinkedList.h LinkedList.cpp ListInterface.h
	g++ -std=c++11 -g -Wall -c Executive.cpp
clean:
	rm *.o LAB5
