#pragma once
#include "AbstractSort.h"
using namespace std;
class SimpleSorting : public AbstractSort {

public:
	SimpleSorting() : AbstractSort{}
	{

	}

	// Begin sorting
	// NOTE: THIS IS SIMILAR TO BUBBLE-SORTING
	void virtual sort(numbers list, int size) {
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++) {
				if (compare(list.at(i), list.at(j))) {
					int tmp = list.at(i);
					list.at(i) = list.at(j);
					list.at(j) = tmp;

				}
			}
		}
	}

	int getNumOfComp() {
		return numOfComp;
	}
	int getNumOfSwaps() {
		return numOfSwaps;
	}
};
/*****************************************************************************************/