#include <iostream>
#include <list>
#include "functions.h"
#include "testsuite.h"

int main()
{
	TestSuite ts;
	/*ts.addTest(Tester(&BubbleSort, "Bubble Sort", &inOrder));
	ts.addTest(Tester(&InsertionSort, "Insertion Sort", &inOrder));
	ts.addTest(Tester(&SelectionSort, "Selection Sort", &inOrder));
	ts.addTest(Tester(&CountSort, "Counting Sort", &inOrder));
	ts.addTest(Tester(&STLSort, "STL Sort", &inOrder));*/
	ts.addTest(Tester(&TreeSortIterative, "Iterative Tree Sort", &inOrder));
	ts.addTest(Tester(&TreeSortRecursive, "Recursive Tree Sort", &inOrder));

	//ts.addData(DataItem(readFile("shortList.txt"), "1,000 numbers"));
	//ts.addData(DataItem(readFile("numbers.txt"), "10,000 numbers"));
	//ts.addData(DataItem(readFile("smallNumbers.txt"), "10,000 small numbers"));
	ts.addData(DataItem(readFile("almostSorted.txt"), "10,000 numbers almost sorted"));
	//ts.addData(DataItem(readFile("descending.txt"), "10,000 numbers descending"));

	ts.RunTests();
	ts.OutputTSVResults("results.tsv");
	return 0;
}