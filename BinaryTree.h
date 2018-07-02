#pragma once

#include "Node.h"

enum places { beforeScan, scannedLeft, scannedValue, scannedRight, beforeDestroy, destroyedLeft, destroyedRight, destroyedValue };
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
	BinaryTree(bool recursive = true);
	~BinaryTree();

	void Insert(Node* n);
	Node* getRoot();
	void DestroyNodeRecursive(Node* n);
	void DestroyNodeIterative(Node* n);
	void InsertRecursive(Node* n, Node* i);
	void InsertIterative(Node* nodeToInsert);

private:
	Node* root;
	bool recursive;
};

