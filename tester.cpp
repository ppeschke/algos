#include <iostream>
using namespace std;
#include "tester.h"

Tester::Tester(pfunc f, vector<int> p, string n)
{
	func = f;
	param = p;
	testName = n;
	pass = false;
}

Tester::~Tester()
{

}

void Tester::RunTest()
{
	clock_t t;
    t = clock();
    func(param);
    t = clock() - t;
    this->clocks = t;
    this->millis = (((float)t)/(CLOCKS_PER_SEC/1000));  //outputs milliseconds
	this->hasBeenRun = true;
}

void Tester::OutputTestResults()
{
	if(this->hasBeenRun)
	{
		cout << endl << this->testName << endl << "Result: " << (this->pass? "PASS" : "FAIL") << endl << this->clocks << " clocks" << endl
		<< "(" << this->millis << " ms)" << endl;
	}
	else
		cout << "Test: \"" << this->testName << "\" has not been run yet!" << endl;
}