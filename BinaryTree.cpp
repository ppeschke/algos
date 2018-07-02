#include <stack>
using namespace std;

#include "BinaryTree.h"

BinaryTree::BinaryTree(bool r)
{
	recursive = r;
	root = nullptr;
}

void BinaryTree::DestroyNodeRecursive(Node* n)
{
	if(n == nullptr)
		return;
	DestroyNodeRecursive(n->getLeft());
	DestroyNodeRecursive(n->getRight());
	delete n;
	return;
}

BinaryTree::~BinaryTree()
{
	if(recursive)
		DestroyNodeRecursive(root);
	else
	{
		TraversalContext currentContext(root, beforeDestroy);
		stack<TraversalContext> parents;
		while(root != nullptr)
		{
			switch(currentContext.place)
			{
			case beforeDestroy:
				currentContext.place = destroyedLeft;
				if(currentContext.node->getLeft() != nullptr)
				{
					parents.push(currentContext);
					currentContext = TraversalContext(currentContext.node->getLeft(), beforeDestroy);
				}
				break;
			case destroyedLeft:
				currentContext.place = destroyedRight;
				if(currentContext.node->getRight() != nullptr)
				{
					parents.push(currentContext);
					currentContext = TraversalContext(currentContext.node->getRight(), beforeDestroy);
				}
				break;
			case destroyedRight:
				delete currentContext.node;
				if(parents.size() > 0)
				{
					currentContext = parents.top();
					parents.pop();
				}
				else
					root = nullptr;
					break;
			}
		}
	}
}

void BinaryTree::InsertRecursive(Node* current, Node* nodeToInsert)
{
	if(nodeToInsert->getValue() < current->getValue())
	{
		if(current->getLeft() != nullptr)
			InsertRecursive(current->getLeft(), nodeToInsert);
		else
			current->setLeft(nodeToInsert);
	}
	else if(nodeToInsert->getValue() > current->getValue())
	{
		if(current->getRight() != nullptr)
			InsertRecursive(current->getRight(), nodeToInsert);
		else
			current->setRight(nodeToInsert);
	}
	else	//equal
		current->incrementInstances();
	return;
}

void BinaryTree::Insert(Node * nodeToInsert)
{
	if(recursive)
	{
		if(root == nullptr)
			root = nodeToInsert;
		else
			InsertRecursive(root, nodeToInsert);
	}
	else
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
}

Node * BinaryTree::getRoot()
{
	return root;
}
