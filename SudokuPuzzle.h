#pragma once
#include <fstream>
#include "CellGroup.h"
#include "Cell.h"
#include <iostream>

using namespace std;

class SudokuPuzzle {
public:
	SudokuPuzzle(void) : m_puzzcellSize(9),	m_innerGridSize(m_puzzcellSize / 3)				// inner grids 3 by 3					
	{									// colon enables 2 variables to be initiated before the constructor
	}									// with a grid size of 9 x 9, inner grids account for a third
	~SudokuPuzzle(void);
	void solve(const char filenameIn[]);
private:
	void Output() const;
	void rowColumnBox(const int rows, const int column, int* outBoxandIndex)const;
	void readPuzzle(const char filenameIn[]);
	int m_puzzcellSize;
	int m_innerGridSize = m_puzzcellSize / 3;			//declared here and above to prevent identifier issues
	CellGroup m_rows[9];
	CellGroup m_columns[9];
	CellGroup m_box[9];
};