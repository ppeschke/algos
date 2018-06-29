#pragma once

#include "Node.h"

enum places { beforeScan, scannedLeft, scannedValue, scannedRight };
struct TraversalContext
{
	Node* node;
	int place;
	TraversalContext(Node* n, places p)
	{
		node = n; place = p;
	}
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void Insert(Node* n);
	Node* getRoot();

private:
	Node* root;
};

