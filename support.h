/* Support.h contains the Sudoku class which contains the funtions for Support.cpp
 */

#ifndef SUPPORT_H
#define SUPPORT_H

#include <iostream>
#define N 9
using namespace std;


class Sudoku{

	public:
		Sudoku();
		void print(int game[N][N]); // parameters: grid
		bool solver(int game[N][N]); // paremeters: grid
		
	private:
		bool isValid(int game[N][N], int, int, int); // parameters: grid, row, column, number
		bool findEmpty(int game[N][N], int &, int &); // parameters: grid, &row, &column
};

#endif
