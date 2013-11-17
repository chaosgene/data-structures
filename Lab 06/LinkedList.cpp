#include <iostream>
#include <sstream>
#include "LinkedList.h"
using namespace std;

// Constructor
LinkedList::LinkedList()
: first(0), mySize(0)
{
}

// Destructor
LinkedList::~LinkedList()
{
	NodePointer ptr = first;
	while (ptr != nullptr)
	{	
		NodePointer next = ptr->next;
		delete ptr;
		ptr = next;
	}
}

// Empty
bool LinkedList::empty() const
{
	return mySize == 0;
}

// Insert
void LinkedList::insert_front(Item i)
{
	NodePointer newnode = new Node(i);
	newnode->next = first;
	first = newnode;
	mySize++;
}

void LinkedList::insert_back(Item i)
{
	NodePointer newnode = new Node(i);
	if (first == nullptr)
	{
		first = newnode;
		newnode->next = nullptr;
	}
	else
	{
		NodePointer ptr = first;
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		ptr->next = newnode;
		newnode->next = nullptr;
	}
	mySize++;
}

// Remove
void LinkedList::delete_front()
{
	if (mySize > 0)
	{
		NodePointer temp = first;
		first = first->next;	
		delete temp;
		mySize--;
	}
	else
	{
	//	cerr << "STOP. This linked-list is already empty." << endl;
	}
}

void LinkedList::delete_back()
{
	if (mySize > 0)
	{
		NodePointer ptr = first;
		if (ptr->next != nullptr)
		{
			while ((ptr->next)->next != nullptr)
			{
				ptr = ptr->next;
			}
			// current ptr is now on second to last node	

			NodePointer temp = ptr->next;
			ptr->next = nullptr;
			delete temp;
		}
		else
		{
			first = nullptr;
			delete ptr;
		}
		mySize--;
	}
	else
	{
	//	cerr << "STOP. This linked-list is already empty." << endl;
	}
}

// Traverse
void LinkedList::print() const
{
	NodePointer ptr = first;
	int count = 1;
	while (ptr != nullptr)
	{	
		cout << "Node #" << count << ": " << endl;
		cout << ptr->data << "\t" << ptr << endl;
		ptr = ptr->next;
		count++;
	}
	cout << "Size: " << mySize << endl;
}