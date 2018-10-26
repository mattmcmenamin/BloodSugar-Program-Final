// LinkedList.cpp


#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}

const List & List::operator=(const List & other)
{
	
	if (&other != this)
	{
		
		this -> ~List();
	
		first_ = clone(other.first_);
	}

	return *this;
}
bool List::operator==(const List & rhs) const {
	/*
	//bool List::operator==(const List &rhs){
	if (this.size() == 0 && rhs.size() == 0) { return true; }//both empty
	if (size() != rhs.size()) { return false; }//sizes not the same

	Node * lptr = this->next_;
	Node * rptr = rhs->next_;
	Double lEntry = lptr->entry_;
	Double rEntry = rptr->entry_;
	while (lptr != NULL && rptr != NULL)
	{
		if (lEntry != rEntry) {
			return false;
		}
		lptr = lptr->next_;
		rptr = rptr->next_;
		lEntry = lptr->entry_;
		rEntry = rptr->entry_;
	}*/
return true;
}






bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(int x)
{
	first_ = new Node(x, first_);
}


int List::removeFirst()
{
	int item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{

		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}



Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}
const int List::size()
{
	if (!empty())
	{
		int total = 0;
		Node* temp = first_;
		while (temp != NULL)
		{
			temp = temp->next_;
			total++;
		}
		return total;

	}
	return 0;
}

const int List::sum()
{
	int overflowcount = 0;
	if (!empty())
	{
		Node* temp = first_;
		int sum = temp->entry_;
		while (temp->next_ != NULL)
		{

			temp = temp->next_;
			if (double(double(sum) + double(temp->entry_)) > double(INT_MAX))
			{
			overflowcount++;
			}
			else
			{
			sum += temp->entry_;
			}
			
		}
		cout << "The program overflowed: " << overflowcount << " times." << endl;
		return sum;
	}
	return 0;
}

const int List::max()
{
	if (!empty())
	{
		Node* temp = first_;
		int max = temp->entry_;
		while (temp->next_ != NULL)
		{
			temp = temp->next_;
			if (temp->entry_ > max)
			{
				max = temp->entry_;
			}
		}
		return max;
	}
	return 0;

}
const int List::min()
{
	if (!empty())
	{
		Node* temp = first_;
		int min = temp->entry_;
		while (temp->next_ != NULL)
		{
			temp = temp->next_;
			if (temp->entry_ < min)
			{
				min = temp->entry_;
			}
		}
		return min;
	}
	return 0;
}






//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}
