#ifndef DATAITEM_H
#define DATAITEM_H

#include <vector>
#include <list>
#include <string>
using namespace std;

#include "Results.h"

class DataItem
{
public:
	DataItem(vector<int> data, string name);
	vector<int> getData();
	string getName();
	void addResults(Results r);
	vector<Results> getResults();

private:
	vector<int> data;
	string name;
	vector<Results> results;
};

#endif