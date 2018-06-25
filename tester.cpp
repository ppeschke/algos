#include <iostream>
using namespace std;
#include "tester.h"

ofstream Tester::logFile;
unsigned int Tester::testCount = 0;

Tester::Tester(pfunc f, vector<int> p, string n, pbfunc vF)
{
	//cout << n << " Constructor. testCount: [" << testCount << " => ";
	func = f;
	param = p;
	testName = n;
	verifyFunc = vF;
	pass = false;
	if(testCount == 0)
	{
		logFile.open("log.txt");
		if(logFile.fail())
		{
			cout << "Log failed to open. Continuing without a log." << endl;
			system("pause");
		}
	}
	++testCount;
	//cout << testCount << "]" << endl;
}

Tester::Tester(const Tester &orig)
{
	//cout << orig.testName << " Copy Constructor. testCount: [" << testCount << " => ";
	this->func = orig.func;
	this->param = orig.param;
	this->verifyFunc = orig.verifyFunc;
	this->testName = orig.testName;
	this->pass = orig.pass;
	++testCount;
	//cout << testCount << "]" << endl;
}

Tester::~Tester()
{
	//cout << testName << " Destructor Called. testCount: [" << testCount << " => ";
	--testCount;
	if(testCount == 0)
		logFile.close();
	//cout << testCount << "]" << endl;
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
		logFile << endl << this->testName << endl << "Result: " << (this->pass ? "PASS" : "FAIL") << endl << this->clocks << " clocks" << endl
			<< "(" << this->millis << " ms)" << endl;
	}
	else
		cout << "Test: \"" << this->testName << "\" has not been run yet!" << endl;
}