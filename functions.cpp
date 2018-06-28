#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <time.h>
#include <algorithm>

#include "functions.h"

void generateFile(string filename, unsigned int range, unsigned int count)
{
	ofstream outfile;
	outfile.open(filename.c_str());
	if(outfile.fail())
	{
		cout << "File failed to open! Aborting..." << endl;
		exit(EXIT_FAILURE);
	}
	unsigned int number;
	srand((unsigned int)time(NULL));
	for(unsigned int i = 0; i < count; ++i)
	{
		number = rand() % range;
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

void writeNumbers(vector<int>& v)
{
	ofstream out("numbersFile.txt");
	if(out.fail())
	{
		cout << "Failed to open numbers.txt file for writing" << endl;
		return;
	}
	for(auto n : v)
	{
		out << n << endl;
	}
	out.close();
}

inline void swap(int * i, int * j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

void BubbleSort(vector<int>& numbers)
{
	bool done = false;
	while(!done)
	{
		done = true;
		for(unsigned int index = 0; index < numbers.size() - 1; ++index)
		{
			if(numbers[index] > numbers[index + 1])
			{
				//swap index and next number
				swap(&numbers[index], &numbers[index + 1]);
				done = false;
			}
		}
	}
}

unsigned int findMax(vector<int>& numbers)
{
	int max;
	if(numbers.size() > 0)
	{
		max = numbers[0];
		for(auto& n : numbers)
		{
			if(n > max)
				max = n;
		}
	}
	return (unsigned int)max;
}

void CountSort(vector<int>& numbers)
{
	unsigned int size = findMax(numbers);
	++size;		//files include 0's
	int* counts = new int[size];
	for(unsigned int i = 0; i < size; ++i)
	{
		counts[i] = 0;
	}
	for(auto& n : numbers)
	{
		++counts[n];
	}
	unsigned int countIndex = 0;
	unsigned int index = 0;
	while(countIndex < size)
	{
		while(counts[countIndex] > 0)
		{
			numbers[index++] = countIndex;
			--counts[countIndex];
		}
		++countIndex;
	}

	delete[] counts;
}

void InsertionSort(vector<int>& numbers)
{
	unsigned int i = 1;
	unsigned int j;
	unsigned int size = numbers.size();
	while(i < size)
	{
		j = i;
		while(j > 0 && numbers[j - 1] > numbers[j])
		{
			swap(&numbers[j], &numbers[j - 1]);
			--j;
		}
		++i;
	}

	i = j;
	return;
}

void selectionSort(vector<int>& numbers)
{
	unsigned int i, j, minIndex;
	unsigned int size = numbers.size();

	// One by one move boundary of unsorted subarray
	for(i = 0; i < size - 1; i++)
	{
		// Find the minimum element in unsorted array
		minIndex = i;
		for(j = i + 1; j < size; ++j)
		{
			if(numbers[j] < numbers[minIndex])
				minIndex = j;
		}

		// Swap the found minimum element with the first element
		swap(&numbers[minIndex], &numbers[i]);
	}
}

void STLSort(vector<int>& numbers)
{
	sort(numbers.begin(), numbers.end());
}

bool inOrder(vector<int>& numbers)
{
	bool sorted = true;
	for(unsigned int i = 0; i < numbers.size() - 1; ++i)
	{
		if(numbers[i] > numbers[i + 1])
			sorted = false;
	}
	return sorted;
}

bool noVerification(vector<int>& numbers)
{
	return true;
}