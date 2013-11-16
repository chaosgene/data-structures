#include <iostream>
#include <cstdlib>

using namespace std;

// Constructor
template <class T>
LinkedList<T>::LinkedList()
: first(0), last(0), mySize(0)
{

}

// Copy Constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &original) 
{	
	first = 0;
	last = 0;
	mySize = 0;
	Node<T> *ptr = original.first;
	while (ptr != nullptr)
	{		
		insert_back(ptr->data);
		ptr = ptr->next;
	}

}


// Assignment Operator
template <class T>
const LinkedList<T> & LinkedList<T>:: operator=(const LinkedList<T> & rhs)
{
	if (this != &rhs)
	{
		// Delete contents of previous linked list
		Node<T> *ptr = first;
		while (ptr != nullptr)
		{	
			Node<T> *next = ptr->next;
			delete ptr;
			ptr = next;
		}
		ptr = rhs.first;
		while (ptr != nullptr)
		{
			insert_back(ptr->data);
			ptr = ptr->next;
		}
	}	
	return *this;
}


// Destructor
template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T> *ptr = first;
	while (ptr != nullptr)
	{	
		Node<T> *next = ptr->next;
		delete ptr;
		ptr = next;
	}
}

// Empty
template <class T>
bool LinkedList<T>::empty() const
{
	return mySize == 0;
}

// Insert
template <class T>
void LinkedList<T>::insert_front(T i)
{
	Node<T> *newnode = new (nothrow) Node<T>(i);
	if ( newnode == nullptr)
	{
		cerr << "Not enough memory left. TERMINATING." << endl;
		exit(1);
	}
	newnode->next = first;
	if (first != nullptr)
		first->prev = newnode;
	else
		last = newnode;
	first = newnode;
	mySize++;
}

template <class T>
void LinkedList<T>::insert_back(T i)
{
	Node<T> *newnode = new (nothrow) Node<T>(i);
	if ( newnode == nullptr)
	{
		cerr << "Not enough memory left. TERMINATING." << endl;
		exit(1);
	}
	if (first == nullptr)
	{
		first = newnode;
	}
	else // the list is non-empty
	{
		last->next = newnode;
		newnode->prev = last;
	}
	last = newnode;
	mySize++;
}

// Remove
template <class T>
void LinkedList<T>::delete_front()
{
	if (mySize > 0)
	{
		Node<T> *temp = first;
		first = first->next;	
		if ( first != nullptr)
			first->prev = nullptr;
		else
			last = nullptr;
		delete temp;
		mySize--;
	}
	else
	{
	//	cerr << "STOP. This linked-list is already empty." << endl;
	}
}

template <class T>
void LinkedList<T>::delete_back()
{
	if (mySize > 0)
	{
		Node<T> *ptr = first;
		if (ptr->next != nullptr)
		{
			Node<T> *temp = last;
			last = temp->prev;
			delete temp;
			last->next = nullptr;
		}
		else
		{
			first = nullptr;
			last = nullptr;
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
template <class T>
void LinkedList<T>::print() const
{
	Node<T> *ptr = first;
	int count = 1;
	cout << "------------------------------------------------------" << endl;
	cout << "First ->->-> " << first << endl;
	cout << "Last ->->-> " << last << endl;
	while (ptr != nullptr)
	{	
		cout << "Node #" << count << ": " << endl;
		cout << ptr->data << "\t" << "@" << ptr << "\t" << "Prev: " << ptr->prev << "\t" << "Next: " << ptr->next <<  endl;
		ptr = ptr->next;
		count++;
	}
	cout << "Size: " << mySize << endl;
	cout << "------------------------------------------------------" << endl;
}

