#include "dataitem.h"

DataItem::DataItem(vector<int> d, string n)
{
	this->name = n;
	this->data = d;
}

vector<int> DataItem::getData()
{
	return data;
}

string DataItem::getName()
{
	return name;
}

void DataItem::addResults(Results r)
{
	this->results.push_back(r);
}

vector<Results> DataItem::getResults()
{
	return this->results;
}
