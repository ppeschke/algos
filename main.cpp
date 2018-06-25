#include <iostream>
#include <list>
#include "functions.h"
#include "tester.h"

int main()
{
	vector<int> numbers = readFile("numbers.txt");
    list<Tester> tests;
	tests.push_back(Tester(&BubbleSort, numbers, "Bubble Sort", &inOrder));
	tests.push_back(Tester(&InsertionSort, numbers, "Insertion Sort", &inOrder));
	tests.push_back(Tester(&selectionSort, numbers, "Selection Sort", &inOrder));

	for(auto& t : tests)
	{
		t.RunTest();
        t.OutputTestResults();
	}
	system("pause");
	return 0;
}