#ifndef TESTER_H
#define TESTER_H

#include <time.h>
#include <vector>

typedef void(*pfunc)(vector<int>&);

class Tester
{
public:
	Tester(pfunc function, vector<int> param, string name);
	~Tester();
	void RunTest();
	void OutputTestResults();

private:
	string testName;
	pfunc func;
	vector<int> param;
	time_t clocks;
	float millis;
	bool hasBeenRun;
	bool pass;
};

#endif