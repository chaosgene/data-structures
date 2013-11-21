#ifndef LINKEDLIST
#define LINKEDLIST
#include "Random.h"

typedef Random Item;
class LinkedList
{
	private:
		class Node
		{
			public:
				Item data;
				Node *next;
				Node(Item specVal) {data = specVal; next = 0;} // Explicit Value Constructor
		};
		typedef Node * NodePointer;	
	public:
		// List's function members
		// Construction		
		LinkedList();
		// Copy Constructor - default required		
		// Assignment Operator - default required
		// Destructor
		~LinkedList();
		// Empty - returns whether linked list contains elements
		bool empty() const;
		// Insert
		void insert_front(Item i); // Add node to the front
		void insert_back(Item i); // Add node to the back
		// Delete (pre-conditions: need items)
		void delete_front(); // Delete a node in the front
		void delete_back(); // Delete a node in the back
		// Traverse - display each node and current size
		void print() const;
	private:
		// List's data members
		NodePointer first; // points to first node
		int mySize; // number of nodes
	
};
#endif
