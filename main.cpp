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
	ts.addTest(Tester(&STLSort, "Standard Template Library Sort", &inOrder));

	ts.addData(DataItem(readFile("shortList.txt"), "1000 numbers randomly distributed"));
	ts.addData(DataItem(readFile("numbers.txt"), "10000 numbers randomly distributed."));

	ts.RunTests();
	ts.OutputResults();
	ts.OutputTSVResults("results.tsv");
	
	system("pause");
	return 0;
}