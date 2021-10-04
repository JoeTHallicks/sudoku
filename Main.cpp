/*Year Two Semester Two  Advance Programming ACW Lab book, Lab 8 (final lab) Sudoku.
Object of the assignment Read in partially completed Sudoku puzzle via text file,
with the aid of pointers, Iterations, etc. Complete the puzzle and output to text file.
Started 8th April 2020, Completed 25th April 2020
Coded by Joseph Hall*/

#include "SudokuPuzzle.h"

using namespace std;	

int main(int argc, char **)						 //Program entry point 
{
	SudokuPuzzle puzzle;
	puzzle.solve("sudoku_puzzle.txt");			//File to be read in.
	
	system("pause");

	return 0;
}
