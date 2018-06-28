#include "Node.h"



Node::Node(int v)
{
	value = v;
	left = nullptr;
	right = nullptr;
	instances = 1;
}


Node::~Node()
{
}
