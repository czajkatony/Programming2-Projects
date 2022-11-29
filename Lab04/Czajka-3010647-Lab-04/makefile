LAB4: main.o Executive.o
	g++ -std=c++11 -g -Wall main.o Executive.o -o LAB4
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
Executive.o: Executive.h Executive.cpp StackInterface.h QueueInterface.h Stack.h Stack.cpp Queue.h Queue.cpp Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp
clean:
	rm *.o LAB4