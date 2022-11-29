Lab07: main.o City.o
	g++ -std=c++11 -g -Wall main.o City.o -o Lab07

main.o: main.cpp City.h
	g++ -std=c++11 -g -Wall -c main.cpp

City.o: City.h City.cpp
	g++ -std=c++11 -g -Wall -c City.cpp

clean:
	rm *.o Lab07
