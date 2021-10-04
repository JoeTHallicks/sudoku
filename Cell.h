#pragma once
#include <vector>
using namespace std;

class Cell
{
public:
	Cell(const int pvalue, const bool pinput);
	Cell();
	~Cell();

	int getCandiListSize() const;
	int getCandidateAt(int index) const;
	int getValue() const;									//Accessors
	bool isInput() const;
	
	void addCandidate(int newCandidate);
	void removeCandidate(int removalCandidate);
	void setValue(int newValue);							//Mutators
	void setInput(bool newValue);
	
private:
	int m_value;
	bool m_input;
	vector<int> m_candidateList;
};

