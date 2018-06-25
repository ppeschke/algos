#include <fstream>
#include <string>
#include <random>
#include <vector>
using namespace std;

void generateFile(string filename)
{
	ofstream outfile;
	outfile.open(filename.c_str());
	if(outfile.fail())
	{
		cout << "File failed to open! Aborting..." << endl;
		exit(EXIT_FAILURE);
	}
	unsigned int number;
	srand(time(NULL));
    for (int i = 0; i < 10000; ++i)
	{
        number = rand() % 100000;
		outfile << number << endl;
	}
	outfile.close();
}

vector<int> readFile(string filename)
{
	vector<int> numbers;
	ifstream infile;
	infile.open(filename);
	int number;
	infile >> number;
	while(!infile.eof())
	{
		numbers.push_back(number);
		infile >> number;
	}
	infile.close();
	return numbers;
}

void outputNumbers(vector<int>& v)
{
	for(auto n : v)
	{
		cout << n << endl;
	}
}

void BubbleSort(vector<int>& numbers)
{
	int temp;
	bool done = false;
	while(!done)
	{
		done = true;
		for(int index = 0; index < numbers.size() - 1; ++index)
		{
			if(numbers[index] > numbers[index + 1])
			{
				//swap index and next number
				temp = numbers[index];
				numbers[index] = numbers[index+1];
				numbers[index + 1] = temp;
				done = false;
			}
		}
	}
}