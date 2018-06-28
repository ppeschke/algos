#include <stack>
using namespace std;

#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	root = nullptr;
}


BinaryTree::~BinaryTree()
{
	Node* currentNode = root;
	stack<Node*> parents;
	while(root != nullptr)
	{
		if(currentNode->getLeft() != nullptr)
		{
			parents.push(currentNode);
			currentNode = currentNode->getLeft();
		}
		else if(currentNode->getRight() != nullptr)
		{
			parents.push(currentNode);
			currentNode = currentNode->getRight();
		}
		else
		{
			delete currentNode;
			if(parents.size() > 0)
			{
				currentNode = parents.top();
				parents.pop();
			}
			else
				root = nullptr;
		}
	}
}

void BinaryTree::Insert(Node * nodeToInsert)
{
	Node* currentNode = root;
	bool done = false;
	while(!done)
	{
		if(currentNode == nullptr)	//inserting at root
		{
			root = nodeToInsert;
			done = true;
		}
		else if (nodeToInsert->getValue() == currentNode->getValue())
		{
			currentNode->incrementInstances();
			done = true;
		}
		else if(nodeToInsert->getValue() < currentNode->getValue())
		{
			if(currentNode->getLeft() == nullptr)
			{
				currentNode->setLeft(nodeToInsert);
				done = true;
			}
			else
				currentNode = currentNode->getLeft();
		}
		else if(nodeToInsert->getValue() > currentNode->getValue())
		{
			if(currentNode->getRight() == nullptr)
			{
				currentNode->setRight(nodeToInsert);
				done = true;
			}
			else
				currentNode = currentNode->getRight();
		}
	}
}

Node * BinaryTree::getRoot()
{
	return root;
}
