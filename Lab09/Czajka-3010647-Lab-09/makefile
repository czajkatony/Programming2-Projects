Lab9: main.o Pokemon.o Executive.o
	g++ -std=c++11 -g -Wall main.o Pokemon.o Executive.o -o Lab9

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Pokemon.o: Pokemon.h
	g++ -std=c++11 -g -Wall -c Pokemon.cpp

Executive.o: Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o Lab9
