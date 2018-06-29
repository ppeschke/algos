#pragma once
class Node
{
public:
	Node(int v);
	~Node();

	int getValue()
	{
		return value;
	}

	Node* getLeft()
	{
		return left;
	}

	Node* getRight()
	{
		return right;
	}

	void setLeft(Node* l)
	{
		left = l;
	}

	void setRight(Node* r)
	{
		right = r;
	}

	void incrementInstances()
	{
		++instances;
	}

	unsigned int getInstances()
	{
		return instances;
	}

private:
	Node* left, *right;
	int value;
	unsigned int instances;
};

