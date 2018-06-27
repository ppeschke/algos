#include <iostream>
using namespace std;
#include "tester.h"

Tester::Tester(pfunc f, vector<int> p, string n, pbfunc vF)
{
	func = f;
	param = p;
	testName = n;
	verifyFunc = vF;
	pass = false;
}

Tester::Tester(const Tester &orig)
{
	this->func = orig.func;
	this->param = orig.param;
	this->verifyFunc = orig.verifyFunc;
	this->testName = orig.testName;
	this->pass = orig.pass;
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
	this->pass = this->verifyFunc(param);
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