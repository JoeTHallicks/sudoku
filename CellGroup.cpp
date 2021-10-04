#include "CellGroup.h"
using namespace std;

CellGroup::CellGroup()
{
	for (int i = 0; i < 9; i++)							//Iterates through the cell objects
	{
		m_cell[i] = new Cell();						
	}
}
CellGroup::~CellGroup()
{		
}
void CellGroup::setCell( int index, Cell * cell)		 //Cell pointers
{
		m_cell[index] = cell;
}
Cell * CellGroup::getCell(int index) const
{
	return m_cell[index];
}