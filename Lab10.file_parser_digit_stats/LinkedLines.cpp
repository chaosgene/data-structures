#include "LinkedLines.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Constructor
LinkedLines::LinkedLines()
{
	numIntegers = 0;
	numDecimals = 0;
	first = nullptr;
}

// Destructor
LinkedLines::~LinkedLines()
{
	Node * ptr = first;
	while (ptr != nullptr)
	{
		Node * next = ptr->next;
		delete [] ptr->data;
		delete ptr;
		ptr = next;
	}
}

// Get # of integers
int LinkedLines::getNumIntegers() const
{
	return numIntegers;
}

// Get # of decimals
int LinkedLines::getNumDecimals() const
{
	return numDecimals;
}

// Traverse for testing
void LinkedLines::traverse()
{
	Node * ptr = first;
	while (ptr != nullptr)
	{
		cout << ptr->number << endl;
		ptr = ptr->next;
	}
}

void LinkedLines::findLinesWithMostOcc(const vector<int> & v)
{
	vector<Node*> nodeMaxVector; // Vector of pointers to Nodes with max occurrences	
	Node * ptr = first;
	vector<int>::const_iterator itr;
	int maxNodeSum = 0;
	while (ptr != nullptr)
	{
		int thisNodeSum = 0;
		// Each node
		// For each value in vector	
		for (itr = v.begin(); itr != v.end(); ++itr)
		{
			thisNodeSum += *(ptr->data + (*itr + 2));
		}	
		
		if (thisNodeSum > maxNodeSum)
		{
			maxNodeSum = thisNodeSum;
			nodeMaxVector.clear();
			nodeMaxVector.push_back(ptr);
		}
		else if (thisNodeSum == maxNodeSum)
		{
			nodeMaxVector.push_back(ptr);
		}
		ptr = ptr->next;
	}
	
	// Sort the max node vector
	sort(nodeMaxVector.begin(), nodeMaxVector.end(), cmpr);

	for (vector<Node*>::iterator itr2 = nodeMaxVector.begin(); itr2 != nodeMaxVector.end(); ++itr2)
	{
		cout << (*itr2)->number << endl;
	}
}
