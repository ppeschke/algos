#include <iostream>
#include <list>
#include "functions.h"
#include "testsuite.h"

int main()
{
	TestSuite ts;
	ts.addTest(Tester(&BubbleSort, "Bubble Sort", &inOrder));
	ts.addTest(Tester(&InsertionSort, "Insertion Sort", &inOrder));
	ts.addTest(Tester(&selectionSort, "Selection Sort", &inOrder));
	ts.addTest(Tester(&CountSort, "Count Sort", &inOrder));
	ts.addTest(Tester(&STLSort, "STL Sort", &inOrder));

	ts.addData(DataItem(readFile("shortList.txt"), "1,000 numbers"));
	ts.addData(DataItem(readFile("numbers.txt"), "10,000 numbers"));
	ts.addData(DataItem(readFile("smallNumbers.txt"), "10,000 small numbers"));
	ts.addData(DataItem(readFile("almostSorted.txt"), "10,000 numbers almost sorted"));
	ts.addData(DataItem(readFile("descending.txt"), "10,000 numbers descending"));

	ts.RunTests();
	ts.OutputTSVResults("results.tsv");
	
	system("pause");
	return 0;
}