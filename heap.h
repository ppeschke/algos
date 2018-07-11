#pragma once
#include <vector>
using namespace std;

class heap
{
public:
	heap(vector<int> h, int num, int max);
	~heap();

	int size() { return n; }
	bool isLeaf(int pos) { return (pos >= n / 2) && (pos < n); }
	int leftchild(int pos) { return 2 * pos + 1; }
	int rightchild(int pos) { return 2 * pos + 2; }
	int parent(int pos) { return (pos - 1) / 2; }
	void buildHeap();
	void insert(int it);
	int removefirst();
	int remove(int pos);

private:
	void siftdown(int pos);
	void swap(int a, int b);

	vector<int> Heap;
	int maxsize;
	int n;
};

