#pragma once
#include <fstream>
using namespace std;
// defining the class
class AbstractSort
{


protected:
	int numOfComp; // number of comparisons
	int numOfSwaps; // number of swaps
	ifstream inFile;

public:
	// constructor
	AbstractSort() {
		numOfComp = 0; // initializes numOfComp to zero
		numOfSwaps = 0; // initializes numOfSwaps to zero
	}
	virtual ~AbstractSort();



	bool compare(int a, int b) {
		numOfComp++;
		if (a > b) {
			return true;
		}
		else {
			numOfSwaps++;
			return false;
		}
	}

	//pure virtual function
	void virtual sort(numbers list, int size) = 0;
};


///**************************************************
///Deconstructor closes files.                      *
///**************************************************
AbstractSort::~AbstractSort()
{
	inFile.close();
}

/*****************************************************************************************/
