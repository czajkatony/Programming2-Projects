Prog: main.o Executive.o ShapeContainer.o Circle.o Rect.o Tri.o
	g++ -std=c++11 -g -Wall main.o Executive.o ShapeContainer.o Circle.o Rect.o Tri.o -o Prog

main.o: main.cpp Executive.h ShapeContainer.h Circle.h Rect.h Tri.h Shape.h
	g++ -std=c++11 -g -Wall -c main.cpp
	
Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

ShapeContainer.o: ShapeContainer.h ShapeContainer.cpp
	g++ -std=c++11 -g -Wall -c ShapeContainer.cpp
	
Circle.o: Circle.h Circle.cpp
	g++ -std=c++11 -g -Wall -c Circle.cpp

Rect.o: Rect.h Rect.cpp
	g++ -std=c++11 -g -Wall -c Rect.cpp
	
Tri.o: Tri.h Tri.cpp
	g++ -std=c++11 -g -Wall -c Tri.cpp
	
clean:
	rm *.o Prog
	