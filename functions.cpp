#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <time.h>
#include <algorithm>
#include <stack>
#include <list>

#include "functions.h"
#include "BinaryTree.h"
#include "heap.h"

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

void fillListRecursive(Node* currentNode, vector<int>& numbers, unsigned int& index)
{
	if(currentNode == nullptr)
		return;
	fillListRecursive(currentNode->getLeft(), numbers, index);
	unsigned int instances = currentNode->getInstances();
	while(instances > 0)
	{
		numbers[index++] = currentNode->getValue();
		--instances;
	}
	fillListRecursive(currentNode->getRight(), numbers, index);
}

void TreeSortRecursive(vector<int>& numbers)
{
	BinaryTree bt;
	//put all numbers into a tree
	for(auto& n : numbers)
	{
		bt.Insert(new Node(n));
	}
	unsigned int index = 0;
	fillListRecursive(bt.getRoot(), numbers, index);
}

void TreeSortIterative(vector<int>& numbers)
{
	BinaryTree bt(false);
	//put all numbers into a tree
	for(auto& n : numbers)
	{
		bt.Insert(new Node(n));
	}
	unsigned int instances;
	TraversalContext currentContext(bt.getRoot(), beforeScan);
	stack<TraversalContext> parents;
	int index = 0;
	bool done = false;
	//iterate a depth-first traversal
	while(!done)
	{
		switch(currentContext.place)
		{
		case beforeScan:
			currentContext.place = scannedLeft;
			if(currentContext.node->getLeft() != nullptr)
			{
				parents.push(currentContext);
				currentContext = TraversalContext(currentContext.node->getLeft(), beforeScan);
			}
			break;
		case scannedLeft:
			currentContext.place = scannedValue;
			instances = currentContext.node->getInstances();
			while(instances > 0)
			{
				numbers[index++] = currentContext.node->getValue();
				--instances;
			}
			break;
		case scannedValue:
			currentContext.place = scannedRight;
			if(currentContext.node->getRight() != nullptr)
			{
				parents.push(currentContext);
				currentContext = TraversalContext(currentContext.node->getRight(), beforeScan);
			}
			break;
		case scannedRight:
			if(parents.size() > 0)
			{
				currentContext = parents.top();
				parents.pop();
			}
			else
			{
				done = true;
			}
			break;
		}
	}
}

void BubbleSort(vector<int>& numbers)
{
	unsigned int size = numbers.size();
	for(unsigned int i = 0; i < size - 1; ++i)
		for(unsigned int j = size - 1; j > i; --j)
			if(numbers[j] < numbers[j - 1])
				swap(&numbers[j], &numbers[j - 1]);
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

void rsort(vector<int>& a, int b[], int n, int digits, int radix, int bins[]);
void RadixSort(vector<int>& numbers)
{
	int* b = new int[numbers.size()];
	int bins[10];
	rsort(numbers, b, numbers.size(), log10(findMax(numbers)) + 1, 10, bins);
	delete[] b;
}

void rsort(vector<int>& a, int b[], int n, int digits, int radix, int bins[])
{
	int j;
	for(int i = 0, rtoi = 1; i < digits; ++i, rtoi *= radix)	//for each digit
	{
		for(j = 0; j < radix; ++j)
		{
			bins[j] = 0;	//initialize count
		}

		//count the number of records for each bin on this phase
		for(j = 0; j < n; ++j)
		{
			++bins[(a[j] / rtoi) % radix];
		}

		//index b: count[j] will be index for last slot of bin j
		for(j = 1; j < radix; ++j)
		{
			bins[j] = bins[j - 1] + bins[j];
		}

		//put records into bins, work from bottom of each bin.
		//since bins fill from bottom, j counts downwards
		for(j = n - 1; j >= 0; --j)
		{
			b[--bins[(a[j] / rtoi) % radix]] = a[j];
		}

		for(j = 0; j < n; ++j)
			a[j] = b[j];		//copy b back to a
	}
}

void InsertionSort(vector<int>& numbers)
{
	unsigned int size = numbers.size();
	for(unsigned int i = 1; i < size; ++i)
		for(unsigned int j = i; j > 0 && numbers[j] < numbers[j - 1]; --j)
			swap(&numbers[j], &numbers[j - 1]);
}

void SelectionSort(vector<int>& numbers)
{
	unsigned int size = numbers.size();
	for(unsigned int i = 0; i < size - 1; ++i)
	{
		unsigned int lowIndex = i;
		for(unsigned int j = size - 1; j > i; --j)
			if(numbers[j] < numbers[lowIndex])
				lowIndex = j;
		swap(&numbers[i], &numbers[lowIndex]);
	}
}

void STLSort(vector<int>& numbers)
{
	sort(numbers.begin(), numbers.end());
}

void HeapSort(vector<int>& numbers)
{
	heap h(numbers, numbers.size(), numbers.size(), &lt);
	unsigned int i = 0;
	while(h.size() > 0)
	{
		numbers[i++] = h.removefirst();
	}
}

inline int findpivot(vector<int>& numbers, int i, int j)
{
	return (i + j) / 2;
}

inline int partition(vector<int>& numbers, int l, int r, int& pivot)
{
	do
	{	//move bounds inward until they meet
		while(numbers[++l] < pivot) {};	//move l right
		while((l < r) && pivot < numbers[--r]) {};	//move r left
		swap(&numbers[l], &numbers[r]);
	} while(l < r);
	return l;
}

void qsort(vector<int>& numbers, int i, int j)
{
	if(j <= i)
		return;	//don't sort 0 or 1 element
	int pivotindex = findpivot(numbers, i, j);
	swap(&numbers[pivotindex], &numbers[j]);	//put pivot at end
	//k will be the first position in the right subarray
	int k = partition(numbers, i - 1, j, numbers[j]);
	swap(&numbers[k], &numbers[j]);
	qsort(numbers, i, k - 1);
	qsort(numbers, k + 1, j);
}

void QuickSort(vector<int>& numbers)
{
	qsort(numbers, 0, numbers.size() - 1);
}

void inssort2(vector<int>& numbers, unsigned int start, unsigned int size, unsigned int incr)
{
	for(unsigned int i = start + incr; i - start < size; i += incr)
		for(unsigned int j = i; j >= start + incr && numbers[j] < numbers[j - incr]; j -= incr)
			swap(&numbers[j], &numbers[j - incr]);
}

void ShellSort(vector<int>& numbers)
{
	unsigned int size = numbers.size();
	for(unsigned int i = size / 2; i > 2; i /= 2)	//for each increment
		for(unsigned int j = 0; j < i; ++j)			//sort each sublist
			inssort2(numbers, j, size - j, i);
	inssort2(numbers, 0, size, 1);
}

const int MSTHRESHOLD = 4;

void msort(vector<int>& numbers, int temp[], int left, int right)
{
	if((right - left) <= MSTHRESHOLD)
	{	//small list
		inssort2(numbers, left, right - left + 1, 1);	//insertion sort every element from left to right
		return;
	}
	int i, j, k, mid = (left + right) / 2;
	msort(numbers, temp, left, mid);
	msort(numbers, temp, mid + 1, right);
	//do the merge operation	first copy two halves to temp
	for(i = mid; i >= left; --i)
		temp[i] = numbers[i];
	for(j = 1; j <= right - mid; ++j)
		temp[right - j + 1] = numbers[j + mid];
	//merge the sublists back to numbers
	for(i = left, j = right, k = left; k <= right; ++k)
		if(temp[i] < temp[j])
			numbers[k] = temp[i++];
		else
			numbers[k] = temp[j--];
}

void MergeSort(vector<int>& numbers)
{
	int* temp = new int[numbers.size()];
	msort(numbers, temp, 0, numbers.size() - 1);
	delete [] temp;
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

bool gt(int a, int b)
{
	return a > b;
}

bool lt(int a, int b)
{
	return a < b;
}