#include <iostream>
#include <list>
#include "functions.h"
#include "tester.h"

int main()
{
    vector<int> numbers = readFile("numbers.txt");
    list<Tester> tests;
    tests.push_back(Tester(&outputNumbers, numbers, "Output Function"));
    tests.push_back(Tester(&BubbleSort, numbers, "Bubble Sort"));
    tests.push_back(Tester(&outputNumbers, numbers, "Output Function 2"));

	for(auto& t : tests)
	{
		t.RunTest();
        t.OutputTestResults();
	}
	system("pause");
	return 0;
}