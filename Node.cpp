// Node.cpp

#include "Node.h"


Node::Node(int entry)
	: entry_(entry), next_(NULL)
{
	cout << "Node( " << entry_ << " ) created" << endl;
}

Node::Node(int entry, Node * next)
	: entry_(entry), next_(next)
{
	cout << "Node( " << entry_ << " ) created" << endl;
}

Node::~Node()
{
	cout << "Node( " << entry_ << ", " << next_ <<
		" ) at " << this << " destroyed" << endl;
}
