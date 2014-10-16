all: main.o Minesweeper.o Record.o IO.o myTime.o
	g++ -o proj1 main.o Minesweeper.o Record.o IO.o myTime.o -lncurses

main.o: proj1.cpp Minesweeper.h
	g++ -c proj1.cpp -o main.o 

Minesweeper.o: Minesweeper.h Minesweeper.cpp
	g++ -c Minesweeper.cpp -o Minesweeper.o

Record.o: Record.h Record.cpp
	g++ -c Record.cpp -o Record.o -lncurses

IO.o: IO.h IO.cpp
	g++ -c IO.cpp -o IO.o -lncurses

myTime.o: myTime.h myTime.cpp
	g++ -c myTime.cpp -o myTime.o -lncurses

clean:
	rm *.o proj1

