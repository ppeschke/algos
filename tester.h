#ifndef TESTER_H
#define TESTER_H

#include <time.h>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

typedef void(*pfunc)(vector<int>&);
typedef bool(*pbfunc)(vector<int>&);

class Tester
{
public:
	Tester(pfunc function, vector<int> param, string name, pbfunc verifyFunc);
	Tester(const Tester &orig);
	~Tester();
	void RunTest();
	void OutputTestResults();

private:
	static ofstream logFile;
	static unsigned int testCount;
	string testName;
	pfunc func;
	pbfunc verifyFunc;
	vector<int> param;
	time_t clocks;
	float millis;
	bool hasBeenRun;
	bool pass;
};

#endif