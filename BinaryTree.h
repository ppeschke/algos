#pragma once

#include "Node.h"

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

