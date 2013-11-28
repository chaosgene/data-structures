#ifndef LINKEDLINES
#define LINKEDLINES
#include <iostream>
#include <string>
#include <vector>
struct Node
{
	int * data; // Pointer to an array of digit distribution
	std::string number; // Double representation of data
	Node(int * idata, std::string number) { data = idata; this->number = number; };
	Node *next;
};

static bool cmpr(const Node * n1, const Node * n2)
{
	return (stod(n1->number) < stod(n2->number));
}

class LinkedLines
{		
	public:
		LinkedLines();
		~LinkedLines();
		void push_front(int * i, std::string number);
		int getNumIntegers() const;
		int getNumDecimals() const;
		void traverse();
		void findLinesWithMostOcc(const std::vector<int> & v);


	private:
		// Data member
		Node * first;
		int numIntegers;
		int numDecimals;
};

// Push back
inline void LinkedLines::push_front(int * i, std::string number)
{

	Node * newnode = new (std::nothrow) Node(i, number);
	if (newnode == nullptr)
	{
		std::cerr << "Not enough memory left. Killed." << std::endl;
		std::exit(1);
	}
	if (*i)
	{
		numDecimals++;
		// cout << "Incremented numDecimals." << endl;
	}
	else
	{
		numIntegers++;
		// cout << "Incremented numIntegers." << endl;
	}
	
	newnode->next = first;
	first = newnode;	
}
#endif
