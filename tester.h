#ifndef TESTER_H
#define TESTER_H

#include <time.h>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#include "Results.h"

typedef void(*pfunc)(vector<int>&);
typedef bool(*pbfunc)(vector<int>&);

class Tester
{
public:
	Tester(pfunc function, string name, pbfunc verifyFunc);
	Tester(const Tester &orig);
	~Tester();
	void RunTest(vector<int>& data);
	string getName();
	time_t getClocks();
	bool getPass();

private:
	string testName;
	pfunc func;
	pbfunc verifyFunc;
	time_t clocks;
	float millis;
	bool hasBeenRun;
	bool pass;
};

#endif