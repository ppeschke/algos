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
	char c[10];
	_itoa_s((int)this->clocks, c, 10);
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
