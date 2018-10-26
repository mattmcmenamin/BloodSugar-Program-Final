// LinkedList.h

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>
using std::ostream;

#include "Node.h"

#define ulong unsigned long


class List
{
public:

	List();

	List(const List & other);

	
	~List();

	
	const List & operator=(const List & other);

	
	bool operator==(const List &rhs) const;


	const int size();

	const int sum();

	const int max();

	const int min();

	bool empty() const;

	void print(ostream & outfile) const;

	void insertAsFirst(int x);

	int removeFirst();

private:
	
	static Node * clone(Node * ptr);


private:
	Node * first_;

};

ostream & operator<<(ostream & outfile, const List & list);

#endif
