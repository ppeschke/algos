#ifndef TESTER_H
#define TESTER_H

#include <time.h>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

typedef void(*pfunc)(vector<int>&);

class Tester
{
public:
	Tester(pfunc function, vector<int> param, string name);
	Tester(const Tester &orig);
	~Tester();
	void RunTest();
	void OutputTestResults();

private:
	static ofstream logFile;
	static unsigned int testCount;
	string testName;
	pfunc func;
	vector<int> param;
	time_t clocks;
	float millis;
	bool hasBeenRun;
	bool pass;
};

#endif