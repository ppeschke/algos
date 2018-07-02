#include <iostream>
using namespace std;
#include "tester.h"
#include "functions.h"

Tester::Tester(pfunc f, string n, pbfunc vF)
{
	func = f;
	testName = n;
	verifyFunc = vF;
	pass = false;
}

Tester::Tester(const Tester &orig)
{
	this->func = orig.func;
	this->verifyFunc = orig.verifyFunc;
	this->testName = orig.testName;
	this->pass = orig.pass;
}

Tester::~Tester()
{
}

void Tester::RunTest(vector<int> data)
{
	vector<int> origData = data;
	time_t testTimes[3];
	clock_t t;
	for(unsigned int i = 0; i < 3; ++i)
	{
		t = clock();
		func(data);
		t = clock() - t;
		testTimes[i] = t;
		if(i != 2)
			data = origData;
	}
    this->clocks = (testTimes[0] + testTimes[1] + testTimes[2])/3;
    this->millis = (((float)t)/(CLOCKS_PER_SEC/1000));  //outputs milliseconds
	this->pass = this->verifyFunc(data);
	this->hasBeenRun = true;
}

string Tester::getName()
{
	return this->testName;
}

time_t Tester::getClocks()
{
	return this->clocks;
}
bool Tester::getPass()
{
	return this->pass;
}