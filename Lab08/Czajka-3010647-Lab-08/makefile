prog: main.o
		g++ -g -std=c++11 -Wall main.o -o prog

main.o: main.cpp ListInterface.h QueueInterface.h StackInterface.h LinkedList.h LinkedList.cpp Node.cpp Node.h Queue.cpp Queue.h Stack.cpp Stack.h
	g++ -g -std=c++11 -Wall -c main.cpp

clean:
	rm *.o prog
