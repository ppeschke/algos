#include <iostream>
#include "functions.h"
#include "tester.h"

int main()
{
    vector<int> numbers = readFile("numbers.txt");
    vector<Tester> tests;
    tests.push_back(Tester(&outputNumbers, numbers, "Output Function"));
    tests.push_back(Tester(&BubbleSort, numbers, "Generic Sorting Algorithm"));
    tests.push_back(Tester(&outputNumbers, numbers, "Output Function"));

	for(auto t : tests)
	{
		t.RunTest();
        t.OutputTestResults();
	}

	return 0;
}