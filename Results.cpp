#include <cstdio>
#include "Results.h"

Results::Results(string a, string d, time_t c, bool p)
{
	algoName = a;
	dataName = d;
	clocks = c;
	pass = p;
}

Results::~Results()
{
}

string Results::getOutputString()
{
	char c[17];
	sprintf(c, "%d", (int)this->clocks);
	string s = '\n' + this->algoName + " run on " + this->dataName + "\nResult: " + (this->pass ? "PASS" : "FAIL") + '\n';
	s += c;
	s += " clocks\n";
	return s;
}

string Results::getDataName()
{
	return this->dataName;
}

time_t Results::getClocks()
{
	return this->clocks;
}

bool Results::getPass()
{
	return this->pass;
}

string Results::getAlgoName()
{
	return this->algoName;
}
