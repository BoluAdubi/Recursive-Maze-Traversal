prog: main.o mazeWalker.o 
	g++ -std=c++11 -g -Wall main.o mazeWalker.o -o prog

main.o: main.cpp mazeWalker.h 
	g++ -std=c++11 -g -Wall -c main.cpp

mazeWalker.o: mazeWalker.h mazeWalker.cpp	
	g++ -std=c++11 -g -Wall -c mazeWalker.cpp

clean:
	rm *.o prog