/*
Author:   Patrick Love

Purpose:  Create a program that can be used to analyze the number of comparisons and swaps
		  performed by a sorting algorithm.

Date:     04/21/2019


*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
typedef vector<int>numbers;


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
		numOfComp++; // get number of comparisons
		if (a > b) {
			return true;
		}
		else {
			numOfSwaps++; // get number of swaps
			return false;
		}
	}

	//pure virtual function
	void virtual sort(numbers list, int size) = 0;
};


/*****************************************************************************************/





class SimpleSorting : public AbstractSort {

public:
	SimpleSorting() : AbstractSort{}
	{

	}

	// Begin sorting
	// NOTE: THIS IS SIMILAR TO BUBBLE-SORTING
	void virtual sort(numbers list, int size) override {
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


	         // functions to get boths swaps and comparisons
	int getNumOfComp() {
		return numOfComp;
	}
	int getNumOfSwaps() {
		return numOfSwaps;
	}
};
/*****************************************************************************************/


///**************************************************
///             BEGIN getData FUNCTION              *
///**************************************************
numbers getData() {
	numbers lst;
	ifstream namesFile;
	//open the .txt file
	namesFile.open("datFile.txt");
	// if there isn't a dataFile
	if (!namesFile) {
		// do this
		perror("Your file wasn't opened correctly");
	}
	// otherwise,
	else {
		// while you don't encounter an end of file error from dataFile
		int count = 0;
		int a;
		while (namesFile) {
			namesFile >> a; // read each number into 'a'
			lst.push_back(a); // push_back each value into the vector
		}
		namesFile.close();
	}
	return lst;
}
/*****************************************************************************************/


///**************************************************
///Deconstructor closes files.                      *
///**************************************************
AbstractSort::~AbstractSort()
{
	inFile.close();
}

/*****************************************************************************************/


///**************************************************
///             BEGIN MAIN FUNCTION                 *
///**************************************************
int main() {
	ifstream inFile;
	int number;
	numbers list = getData();
	int size = list.size();





	// creating object for SimpleSorting
	SimpleSorting* abstrsort = new SimpleSorting();

	//calling sort method
	abstrsort->sort(list, size);


	//output comparisons and swaps to the console
	cout << "Number of comparisons: " << abstrsort->getNumOfComp() << endl;
	cout << "Number of swaps: " << abstrsort->getNumOfSwaps() << endl;
	system("pause");
	return 0;
}

/*****************************************************************************************/
