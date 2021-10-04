#include "SudokuPuzzle.h"
#include <chrono>

using namespace std;

SudokuPuzzle::~SudokuPuzzle(void) 
{}
void SudokuPuzzle::solve(const char filenameIn[])
{
	readPuzzle(filenameIn);												//Reads in puzzle from text file
	const auto startTime = std::chrono::high_resolution_clock::now();	// gets start time for clock timer
	int explorationRounds = 0;
	int cellBlock[2];
	bool correctInput = true;											// this code solves the actual puzzle
	do
	{
		correctInput = true;
		explorationRounds++;
		for (int row = 0; row < m_puzzcellSize; row++)
		{
			for (int column = 0; column < m_puzzcellSize; column++)
			{
				if (!m_rows[row].getCell(column)->isInput())			//value equal zero?
				{
					if (m_rows[row].getCell(column)->getValue() == 0)
					{
						correctInput = false;							// puzzle not solved
						rowColumnBox(row, column, &cellBlock[0]);		// list reduces , square equal to zero
						for (int i = 0; i < 9; i++)
						{
							if (!m_rows[row].getCell(i)->getValue() == 0)			//Getter, row iteration/checking rows
							{
								m_rows[row].getCell(column)->						//Getter
									removeCandidate(m_rows[row].getCell(i)->getValue());	//if not remove from list
							}
							if (!m_columns[column].getCell(i)->getValue() == 0) //Getter, column iteration/checking columns
							{
								m_columns[column].getCell(row)->
									removeCandidate(m_columns[column].getCell(i)->getValue());	//if not remove from list
							}
							if (!m_box[cellBlock[0]].getCell(i)->getValue() == 0)	// checking boxes/ if not remove from list
							{
								m_box[cellBlock[0]].getCell(cellBlock[1])->
									removeCandidate(m_box[cellBlock[0]].getCell(i)->getValue());
							}
						}
						if (m_rows[row].getCell(column)->getCandiListSize() == 1) {	//if list is 1, gridcell is 0 in list
							m_rows[row].getCell(column)->setValue(m_rows[row].getCell(column)->getCandidateAt(0));
						}
					}
				}
			}
		}
	} while (!correctInput);
		const auto endTime = std::chrono::high_resolution_clock::now();		//end time
		const auto duration = (endTime - startTime).count();
		cout << "Completed in: " << endl;
		cout << duration << "milliseconds" << std::endl;
		cout << explorationRounds << " exploration rounds" << endl << endl;			//compile time in nanoseconds
		Output();
	
}
void SudokuPuzzle::readPuzzle(const char filenameIn[]) 
{
	ifstream fin(filenameIn);
	int cellBlock[2];
	for (int row = 0; row < m_puzzcellSize; row++)								//import into rows
	{
		for (int column = 0; column < m_puzzcellSize; column++)
		{
			int currentValue;
			bool currentInput = true;
			fin >> currentValue;
			if (currentValue == 0)
			{
				currentInput = false;			//input is zero  not provided by puzzle
			}

			m_rows[row].setCell(column, new Cell(currentValue, currentInput));		//input cells in grid rows

			m_columns[column].setCell(row, m_rows[row].getCell(column));			//input cells in grid columns			
			rowColumnBox(row, column, &cellBlock[0]);
			m_box[cellBlock[0]].setCell(cellBlock[1], m_rows[row].getCell(column));	//input cell in boxes
		}
	}
}
void SudokuPuzzle::rowColumnBox(const int row, const int column, int* outBoxandIndex) const
{
	const int boxRow = row / 3;	
	const int boxColumn = column / 3;
	int boxIndex = 0;
	int boxRowValueIndex = 0;							//representing row value
	int boxColumnValueIndex = 0;						//representing column value
	int boxValueIndex = 0;								//representing box value

	if (boxRow == 0) {
		boxIndex = boxColumn;							//Adding all row values
		boxRowValueIndex = row;
	}
	else if (boxRow == 1) {
		boxIndex = 3 + boxColumn;
		boxRowValueIndex = row - 3;
	}
	else {
		boxIndex = 6 + boxColumn;
		boxRowValueIndex = row - 6;
	}
	if (boxColumn == 0) {								//Adding all column values
		boxColumnValueIndex = column;
	}
	else if (boxColumn == 1) {
		boxColumnValueIndex = column - 3;
	}
	else {
		boxColumnValueIndex = column - 6;
	}
	boxValueIndex = boxColumnValueIndex + (boxRowValueIndex * 3);
	outBoxandIndex[0] = boxIndex;
	outBoxandIndex[1] = boxValueIndex;
}
void SudokuPuzzle::Output() const 
{
	ofstream fout("sudoku_solution.txt");				//writing out to solution text file
	if (fout.is_open())
	{
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				fout << m_rows[y].getCell(x)->getValue() << " ";
			}
			fout << endl;
		}
		fout.close();
	}
}