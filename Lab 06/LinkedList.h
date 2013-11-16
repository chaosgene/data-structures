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
		//void insert_after(Item i, NodePointer current); // Insert a node containing Item i after a certain node pointer
		//void insert_at(Item i, NodePointer place); // Insert a node at a certain address already in the linked list, shifting stuff after in the list down
		// Delete (pre-conditions: need items)
		void delete_front(); // Delete a node in the front
		void delete_back(); // Delete a node in the back
		//void delete_after(NodePointer current); // Delete the node after the current pointer
		//void delete_at(NodePointer place); // Delete a node at a certain address already in the linked list, shifting stuff after up
		// Traverse - display each node and current size
		void print() const;
		// Search
		//NodePointer search(Item i); // Return the address of the node containing i
		//NodePointer getfirst() const; // Return the address of the first node
	private:
		// List's data members
		NodePointer first; // points to first node
		int mySize; // number of nodes
	
};
// Overloaded output operator
//std::ostream &operator<< (std::ostream &out, const LinkedList &aList);
//std::istream &operator>> (std::istream &in, LinkedList &aList);
#endif
