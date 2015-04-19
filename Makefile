all: Sudoku.o givequestion.cpp solve.cpp
	g++ -o givequestion givequestion.cpp Sudoku.o
	g++ -o solve solve.cpp Sudoku.o

Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp -o Sudoku.o