#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <list>
#include <vector>
using namespace std;
#include "tester.h"

class TestSuite
{
public:
	void addTest(Tester t);
	void addData(vector<int>& d);
	void RunTests();
	void outputResults();

private:
	list<Tester> tests;
	list<vector<int> > datas;
};

#endif