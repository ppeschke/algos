#ifndef TESTSUITE_H
#define TESTSUITE_H

#include "tester.h"
#include "dataitem.h"
#include "Results.h"

class TestSuite
{
public:
	void addTest(Tester t);
	void addData(DataItem di);
	void RunTests();
	void OutputResults();
	void OutputTSVResults(string filename);

private:
	vector<Tester> tests;
	vector<DataItem> dataSets;
};

#endif