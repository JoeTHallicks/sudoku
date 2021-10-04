#pragma once
#include "Cell.h"
#include "CellGroup.h"

class CellGroup
{
public:
	CellGroup();
	~CellGroup();

	void setCell(const int index, Cell *cell);			//Array of nine pointers to cell objects
	Cell* getCell(int index) const;

private:
	Cell* m_cell[9];									//Array of nine cell group objects
};

