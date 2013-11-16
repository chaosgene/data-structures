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
/*
void LinkedList::insert_after(Item i, NodePointer current)
{
	if (current == nullptr)
	{
		LinkedList::insert_front(i);
	}
	else if (current->next == nullptr)
	{
		LinkedList::insert_back(i);
	}
	else
	{
		NodePointer newnode = new Node(i);
		NodePointer ptr = first;
		bool found = false;
		while ((ptr != nullptr) && !found) // End when all elements are tested or a match is found
		{
			if( ptr  == current)
			{
				newnode->next = ptr->next;
				ptr->next = newnode;
				found = true;
				mySize++;
			}
			ptr = ptr->next;
		}
	}		
}

void LinkedList::insert_at(Item i, NodePointer current)
{
	if (current == nullptr)
	{
		cerr << "Trying to insert at a node memory address not currently in the linked list." << endl;
		return;
	}
	NodePointer ptr = first;
	if (ptr == current)
	{	
		LinkedList::insert_front(i);
		return;
	}
	bool found = false;
	while ((ptr != nullptr) && !found) // End when all elements are tested or a match is found
	{
		if(ptr->next == current) // When ptr is the predecessor 
		{
			NodePointer newnode = new Node(i);
			ptr->next = newnode;
			newnode->next = current;
			found = true;
			mySize++;
		}
		ptr = ptr->next;
	}
}
*/
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
/*
void LinkedList::delete_after(NodePointer current)
{
	NodePointer temp = first;
	bool found = false;
	while ((temp != nullptr) && !found)
	{
		if (temp == current)
		{
			if (temp->next != nullptr)			
			{
				NodePointer junk = temp->next;
				temp->next = junk->next;
				delete junk;
				found = true;
				mySize--;
			}
		}
		temp = temp->next;
	}
}

void LinkedList::delete_at(NodePointer place)
{
	if (place == first)
	{
		LinkedList::delete_front();
		return;
	}	
	else if (place == nullptr)
	{
		cerr << "Stop. Cannot delete at a nullptr node." << endl;
		return;
	}
	else if (place->next == nullptr)
	{
		LinkedList::delete_back();
		return;
	}
	NodePointer ptr = first;
	bool found = false;
	while ((ptr != nullptr) && !found)
	{
		if (ptr->next == place)
		{
			// ptr is now at the predecessor
			NodePointer junk = ptr->next;
			ptr->next = junk->next;
			delete junk;
			found = true;
			mySize--;
		}
		ptr = ptr->next;
	}
}

// Search
LinkedList::NodePointer LinkedList::search(Item i)
{
	NodePointer temp = first;
	NodePointer returnV = nullptr;
	bool found = false;
	//cout << "Starting a search for: " << i << endl;
	while ((temp != nullptr) && !found)
	{
		//cout << "Does " << temp->data << " match up with " << i << "?" << endl;
		if (temp->data == i)
		{
			//cout << "Yes." << endl;
			returnV = temp;
			found = true;
		}
		temp = temp->next;
	}
	return returnV;
}

// Get first node
LinkedList::NodePointer LinkedList::getfirst() const
{
	return first;
}
*/
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
/*
ostream &operator<< (ostream &out, const LinkedList &aList)
{
	aList.print(out);
	return out;
}


istream &operator>> (istream &in, LinkedList &aList)
{
	// Currently applicable only to integers
	std::string input = "";
	std::stringstream ss;
	int value;
	bool valid;

	cout << "Manually populate a linked list." << endl;
	

	cout << "Please enter an integer or type 'exit' to finish: " << endl;
	in >> input;

	while(input != "exit")
	{
		for (unsigned int i = 0; i < input.length(); i++)
		{
			if (i == 0 && input[i] == '-')
			{
				valid = false; // negative number, need to verify next digit
			}
			else if (isdigit(input[i]))
			{
			valid = true;
		}
		else
		{
			valid = false;
			break;
		}
		} 
		
		if (valid)
		{
			ss.clear();
			ss << input;
			ss >> value;
			cout << "Adding " << value << " to the linked list." << endl << endl;
			aList.insert_back(value);
		}
		else
		{
			cout << "Not an integer! Enter an integer please." << endl;
		}
		
		cout << "Please enter an integer or type 'exit' to finish: " << endl;
		in >> input;
	}
	return in;
}
*/
