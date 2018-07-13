#include <iostream>
#include <list>
#include "functions.h"
#include "testsuite.h"

int main()
{
	TestSuite ts;
//#define DEBUG
#ifdef DEBUG
	//DEBUG TESTING
	vector<int> debugList;
	debugList.push_back(7);
	debugList.push_back(6);
	debugList.push_back(5);
	debugList.push_back(4);
	debugList.push_back(3);
	debugList.push_back(2);
	debugList.push_back(1);
	ts.addData(DataItem(debugList, "Debug Numbers"));
	ts.addTest(Tester(&BinSort, "Bin Sort", &inOrder));
#endif
#ifndef DEBUG
	//NORMAL TESTING
	ts.addTest(Tester(&STLSort, "STL Sort", &inOrder));
	ts.addTest(Tester(&QuickSort, "Quick Sort", &inOrder));
	ts.addTest(Tester(&CountSort, "Counting Sort", &inOrder));
	ts.addTest(Tester(&ShellSort, "Shell Sort", &inOrder));
	ts.addTest(Tester(&MergeSort, "Merge Sort", &inOrder));
	ts.addTest(Tester(&HeapSort, "Heap Sort", &inOrder));
	ts.addTest(Tester(&TreeSortRecursive, "Recursive Tree Sort", &inOrder));
	ts.addTest(Tester(&TreeSortIterative, "Iterative Tree Sort", &inOrder));
	ts.addTest(Tester(&SelectionSort, "Selection Sort", &inOrder));
	ts.addTest(Tester(&InsertionSort, "Insertion Sort", &inOrder));
	ts.addTest(Tester(&BubbleSort, "Bubble Sort", &inOrder));

	ts.addData(DataItem(readFile("shortList.txt"), "1,000 numbers"));
	ts.addData(DataItem(readFile("numbers.txt"), "10,000 numbers"));
	ts.addData(DataItem(readFile("smallNumbers.txt"), "10,000 small numbers"));
	ts.addData(DataItem(readFile("almostSorted.txt"), "10,000 numbers almost sorted"));
	ts.addData(DataItem(readFile("descending.txt"), "10,000 numbers descending"));

#endif
	ts.RunTests();
	ts.OutputTSVResults("results.tsv");
	system("pause");
	return 0;
}