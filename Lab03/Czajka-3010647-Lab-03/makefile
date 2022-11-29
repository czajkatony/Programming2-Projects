Prog: main.o Node.o StackOfChars.o StackTester.o ParserDriver.o
	g++ -std=c++11 -g -Wall main.o Node.o StackOfChars.o StackTester.o ParserDriver.o -o Prog

main.o: main.cpp Node.h StackOfChars.h StackTester.h ParserDriver.h
	g++ -std=c++11 -g -Wall -c main.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp

StackOfChar.o: StackOfChars.h StackOfChars.cpp
	g++ -std=c++11 -g -Wall -c StackOfChars.cpp
	
StackTester.o: StackTester.h StackTester.cpp
	g++ -std=c++11 -g -Wall -c StackTester.cpp

ParserDriver.o: ParserDriver.h ParserDriver.cpp
	g++ -std=c++11 -g -Wall -c ParserDriver.cpp
	
clean:
	rm *.o Prog