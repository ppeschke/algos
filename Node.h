#pragma once
class Node
{
public:
	Node(int v);
	~Node();

	int Node::getValue()
	{
		return value;
	}

	Node* Node::getLeft()
	{
		return left;
	}

	Node* Node::getRight()
	{
		return right;
	}

	void Node::setLeft(Node* l)
	{
		left = l;
	}

	void Node::setRight(Node* r)
	{
		right = r;
	}

	void Node::incrementInstances()
	{
		++instances;
	}

	unsigned int Node::getInstances()
	{
		return instances;
	}

private:
	Node* left, *right;
	int value;
	unsigned int instances;
};

