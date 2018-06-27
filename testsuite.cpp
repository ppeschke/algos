#include <iostream>
#include "testsuite.h"

void TestSuite::addTest(Tester t)
{
	tests.push_back(t);
}

void TestSuite::addData(DataItem di)
{
	dataSets.push_back(di);
}

void TestSuite::RunTests()
{
	for(auto& d : dataSets)
	{
		for(auto& algo : tests)
		{
			cout << "Running " << algo.getName() << " on " << d.getName() << endl;
			algo.RunTest(d.getData());
			d.addResults(Results(algo.getName(), d.getName(), algo.getClocks(), algo.getPass()));
		}
	}
}

void TestSuite::OutputResults()
{
	for(unsigned int dIndex = 0; dIndex < dataSets.size(); ++dIndex)
	{
		for(unsigned int rIndex = 0; rIndex < dataSets[dIndex].getResults().size(); ++rIndex)
		{
			cout << dataSets[dIndex].getResults()[rIndex].getOutputString() << endl;
		}
	}
}

void TestSuite::OutputTSVResults(string filename)
{
	//setup table
	time_t** times = new time_t*[this->dataSets.size()];
	for(unsigned int i = 0; i < this->dataSets.size(); ++i)
	{
		times[i] = new time_t[this->tests.size()];
	}
	
	ofstream outFile(filename.c_str());
	if(outFile.fail())
	{
		cout << "Filed to open output file." << endl;
	}
	//output data set names
	for(auto& d : dataSets)
	{
		outFile << '\t' << d.getName();
	}
	outFile << endl;

	//fill table
	for(unsigned int d = 0; d < dataSets.size(); ++d)
	{
		time_t totalTime = 0;
		for(auto& r : dataSets[d].getResults())
			totalTime += r.getClocks();
		for(unsigned int a = 0; a < tests.size(); ++a)
			times[d][a] = dataSets[d].getResults()[a].getClocks();
	}

	//output algorithm names and times
	for(unsigned int a = 0; a < tests.size(); ++a)
	{
		outFile << tests[a].getName();
		for(unsigned int d = 0; d < dataSets.size(); ++d)
		{
			outFile << '\t' << times[d][a];
		}
		outFile << endl;
	}

	outFile.close();

	//delete table
	for(unsigned int i = 0; i < this->dataSets.size(); ++i)
	{
		delete [] times[i];
	}
	delete [] times;
}
