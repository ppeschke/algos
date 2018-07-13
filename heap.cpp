#include "heap.h"
#include <cassert>
#include <iostream>
using namespace std;

heap::heap(vector<int> h, int num, int max, bool(*c)(int, int))
{
	Heap = h;
	n = num;
	maxsize = max;
	comp = c;


	buildHeap();
}


heap::~heap()
{
}

void heap::swap(int a, int b)
{
	int temp = Heap[a];
	Heap[a] = Heap[b];
	Heap[b] = temp;
}

void heap::siftdown(int pos)
{
	while(!isLeaf(pos))
	{
		int j = leftchild(pos);
		int rc = rightchild(pos);
		if((rc < n) && comp(Heap[rc], Heap[j]))
			j = rc;
		if(!comp(Heap[pos], Heap[j]))
			swap(pos, j);
		pos = j;
	}
}

void heap::buildHeap()
{
	for(int i = n / 2 - 1; i >= 0; --i)
		siftdown(i);
}

void heap::insert(int it)
{
	assert(n < maxsize);
	int curr = n++;
	Heap[curr] = it;	//start at end of heap
	//now sift up until curr's parent < curr
	while((curr != 0) && comp(Heap[curr], Heap[parent(curr)]))
	{
		swap(curr, parent(curr));
		curr = parent(curr);
	}
}

int heap::removefirst()
{
	assert(n > 0);
	swap(0, --n);
	if(n != 0)
		siftdown(0);
	return Heap[n];
}

int heap::remove(int pos)
{
	assert((pos >= 0) && (pos < n));
	if(pos == (n - 1))	//last element, no work to do
		--n;
	else
	{
		swap(pos, --n);
		while((pos != 0) && comp(Heap[pos], Heap[parent(pos)]))
		{
			swap(pos, parent(pos));
			pos = parent(pos);
		}
		if(n != 0)
			siftdown(pos);
	}
	return Heap[n];
}