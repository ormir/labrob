labrob: main.o labyrinth.o recursive.o robot.o tremaux.o wallflower.o
		g++ -std=c++11 main.o labyrinth.o recursive.o robot.o tremaux.o wallflower.o -o labrob

main.o: main.cpp 
		g++ -std=c++11 -c main.cpp

labyrinth.o: labyrinth.cpp labyrinth.hpp
		g++ -std=c++11 -c labyrinth.cpp

recursive.o: recursive.cpp recursive.hpp
		g++ -std=c++11 -c recursive.cpp

robot.o: robot.cpp robot.hpp
		g++ -std=c++11 -c robot.cpp

tremaux.o: tremaux.cpp tremaux.hpp
		g++ -std=c++11 -c tremaux.cpp

wallflower.o: wallflower.cpp wallflower.hpp
		g++ -std=c++11 -c wallflower.cpp

start: labrob
		./labrob maze1_small.txt

clean:
		rm *.o labrob