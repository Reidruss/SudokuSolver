#include <iostream>
#include "support.h"

#define N 9
using namespace std;


Sudoku::Sudoku(){} // constructor

// Prints the grid when called
void Sudoku::print(int grid[N][N]){
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j)
			cout << grid[i][j] << " ";
		
		cout << endl;
	}
}

// Finds the empty cell in the puzzle( if the cell is 0 then is empty)
bool Sudoku::findEmpty(int grid[N][N], int &row, int &column){

	for(row = 0; row < N; ++row){
		for(column = 0; column < N; ++column){
			if(grid[row][column] == 0)
				return true;
		}		
	}

	return false;

}
// if the current number is not present in row/column or 3x3 box
bool Sudoku::isValid(int grid[N][N], int row, int column, int number){
		
		//if used in column
		for(int i = 0; i < N; ++i){
			if(grid[i][column] == number)
				return false;
		}
		
		// if used in row
		for(int j = 0; j < N; ++j){
			if(grid[row][j] == number)
				return false;
		}

		int boxRow = row - row % 3;
		int boxColumn = column - column % 3;

		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				if(grid[boxRow + i][boxColumn + j] == number)
					return false;
			}
		}

		return true;
}

bool Sudoku::solver(int grid[N][N]){
	int row, column;

	if(!findEmpty(grid, row, column))
		return true;
	
	for(int i = 1; i <= N; ++i){
		if(isValid(grid, row, column, i)){
			grid[row][column] = i;

			if(solver(grid))
				return true;

			grid[row][column] = 0;
		}
	}
	return false;
}



