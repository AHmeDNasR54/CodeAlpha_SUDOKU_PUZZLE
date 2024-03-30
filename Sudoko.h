#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
#include<direct.h>
#include<iomanip>
using namespace std;
class Sudoko
{
private:
	 int N;
	int**grid;
	int** solvedGrid;

public:
	Sudoko();
	void setArray(int N);
	bool isSafe(int row, int col, int num);
	bool solveSudoku();
	void printGrid() const;
	void printSolvedGrid()const;
	void generatePuzzle();
	bool validateSolution();
	void userSolvePuzzle();
	// Function for user to provide a Sudoku puzzle
	void userProvidedPuzzle() const; 
	~Sudoko();
};

