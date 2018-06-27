#include "testsuite.h"

void TestSuite::addTest(Tester t)
{
	tests.push_back(t);
}

void TestSuite::addData(vector<int>& d)
{
	datas.push_back(d);
}