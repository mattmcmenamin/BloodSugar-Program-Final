// Node.h

#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
using std::cout;
using std::endl;


class Node
{
public:
	int entry_;
	Node * next_;

public:
	
	explicit Node(int entry);


	Node(int entry, Node * next);


	~Node();

private:
	Node();
	Node(const Node &);
	const Node & operator=(const Node &);
};

#endif