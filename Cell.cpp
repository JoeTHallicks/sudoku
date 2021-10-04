#include "Cell.h"
using namespace std;

Cell::Cell(const int pvalue, const bool pinput){
	m_value = pvalue;
	m_input = pinput;
	for (int i = 1; i <= 9; i++)					 //candidate list inputs
	{
		m_candidateList.push_back(i);
	}
}
Cell::~Cell()
{}
Cell::Cell(){
	m_value = 0;
	m_input = false;
	for (int i = 1; i <= 9; i++)					//Iterating through each Candidate list
	{												
		m_candidateList.push_back(i);
	}
}
int Cell::getValue() const						// Getter.
{
	return m_value;
}

bool Cell::isInput() const
{
	return m_input;									//Checking for correct Input number
}

int Cell::getCandiListSize() const				//Getter.
{
	return m_candidateList.size();
 }
int Cell::getCandidateAt(const int index) const	//Getter.
{
	return m_candidateList[index];
}

void Cell::setValue(const int newValue)			//Setter.
{
	m_value = newValue;
}

void Cell::setInput(const bool newValue)			//Setter.
{
	m_input = newValue;
}

void Cell::addCandidate(const int newCandidate)
{
	bool isDuplicate = false;
	for (size_t i = 0; i < m_candidateList.size(); i++) {		//Checking if inputted candidate already exist.
		if (m_candidateList[i] == newCandidate) {
			isDuplicate = true;
		}
	}
	if (!isDuplicate) {
		m_candidateList.push_back(newCandidate);
	}
}
void Cell::removeCandidate( const int removalCandidate)		//Removes candidate if not requiewd
{
	for (size_t i = 0; i < m_candidateList.size(); i++) {
		if (m_candidateList[i] == removalCandidate) {
			m_candidateList.erase(m_candidateList.begin() + i);
		}
	}
};
