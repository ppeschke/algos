#ifndef RESULTS_H
#define RESULTS_H

#include <string>
#include <time.h>
using namespace std;

class Results
{
public:
	Results(string, string, time_t, bool);
	~Results();

	string getOutputString();
	string getAlgoName();
	string getDataName();
	time_t getClocks();
	bool getPass();

private:
	string algoName;
	string dataName;
	time_t clocks;
	bool pass;
};

#endif