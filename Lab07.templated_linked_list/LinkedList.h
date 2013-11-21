#ifndef LINKEDLIST
#define LINKEDLIST

template <class T>
struct Node
{
	Node(T data) : data(data), next(0), prev(0) {}
	T data;
	Node *next;
	Node *prev;
};
template <class T>
class LinkedList
{
	private:
	public:
		// List's function members
		// Construction		
		LinkedList();
		//Copy Constructor - explicit required	
		LinkedList(const LinkedList<T> & original);
		// Assignment Operator - default required
		const LinkedList<T> & operator=(const LinkedList<T> & rhs);
		// Destructor
		~LinkedList();
		// Empty - returns whether linked list contains elements
		bool empty() const;
		// Insert
		void insert_front(T i); // Add node to the front
		void insert_back(T i); // Add node to the back
		// Delete (pre-conditions: need items)
		void delete_front(); // Delete a node in the front
		void delete_back(); // Delete a node in the back
		// Traverse - display each node and current size
		void print() const;
	private:
		// List's data members
		Node<T> *first; // points to first node
		Node<T> *last; // points to last node
		int mySize; // number of nodes
	
};
#include "LinkedList.cc"
#endif
