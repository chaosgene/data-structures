#include <iostream>
#include "StatisticsProcessor.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
/*
Name: Christopher Zhang
Lab: 03
Section: A51
*/
/*
	Default Constructor
	Create an empty statistics processor that takes no data.
*/
StatisticsProcessor::StatisticsProcessor()
{	
	d = new DynamicArray;
}
/*
	Copy Constructor
*/
StatisticsProcessor::StatisticsProcessor(const StatisticsProcessor &s)
{
	d = new DynamicArray;
	//cout << "copying from" << endl;
	for (int i = 0; i < s.d->size(); i++)
	{
		d->push_back(s.d->getValueAtIndex(i));
	}
}

/*
	Assignment Operator
*/
StatisticsProcessor& StatisticsProcessor::operator=(const StatisticsProcessor &rhs)
{
	if (this != &rhs) // Alias test
	{
		delete d;
		d = new DynamicArray;
		cout << rhs.d->size();
		for (int i = 0; i < rhs.d->size(); i++)
		{
			d->push_back(rhs.d->getValueAtIndex(i));
		}
	}
	return *this;
}
/*
	Destructor
*/
StatisticsProcessor::~StatisticsProcessor()
{
	delete d;
}
/*
	Add data to the data set loaded from a file.
	First line of the file contains the number of data elements in the file.
	Each remaining line contains a single integer.
*/
void StatisticsProcessor::loadData(std::string file_name)
{
	string line;
	ifstream myfilestream (file_name);
	if (myfilestream.is_open())
	{
		getline(myfilestream,line); // Get the first line of the file
		//cout << "Number of Data Entries: " << line << endl;
		int numbLines;
		istringstream ( line ) >> numbLines; // numb now contains the number of lines to be read from the file for input
		
		int currentEntry;
		for (int i = 0; i < numbLines; i++)
		{
			getline(myfilestream,line);
			istringstream ( line ) >> currentEntry;
			d->push_back(currentEntry);
			//cout << "Added: " << currentEntry << " to our dataset." << endl;
		}
		myfilestream.close();
	}
	else cout << "Unable to open file"; // throw file does not exist exception
}
/*
	Add data to the data set from the command-line.
	First prompt for number of entries to be added.
	Then prompt user to add them one at a time. 
	Check each for a valid number.
*/
istream& operator>>(istream &in, StatisticsProcessor &s)
{
	int numbEntries;
	
	
	std::string posNumEntries; // Inputs
	
	
	cout << "How many entries are to be entered?" << endl;
	
	in >> posNumEntries;
	int posNumEntriesLength = posNumEntries.length();
	
	bool f = false; // f means if checking needs to be further done
	
	while (!f)
	{
		bool t = true; // t means if we don't need to check again after this one
		for (int i = 0; i < posNumEntriesLength; i++)
		{
			if (!isdigit(posNumEntries[i])&& (posNumEntries[i] != '-'))
			{
				cout << posNumEntries[i] << " is not a number." << endl;
				t = false; // we need to check again
			}
		}
		// check to see if valid again
		if (t) // meaning all is well
		{
			f = true;
		}
		else
		{
		
		cout << "Wrong input. Try again with an integer." << endl;
		in >> posNumEntries;
		posNumEntriesLength = posNumEntries.length();
		}
	}
	stringstream ss(posNumEntries);
	ss >> numbEntries;
	if (numbEntries < 0)
	{
		numbEntries = 0;
	}
	
	int x;
	std::string posX;
	
	for (int i = 0; i < numbEntries; i++)
	{
		cout << "Please enter the integer data value." << endl;
		in >> posX;
		int posXLength = posX.length();
		bool f2 = false; // f2 means if checking needs to be further done
	
		while (!f2)
		{
			bool t2 = true; // t means if we don't need to check again after this one
			for (int i = 0; i < posXLength; i++)
			{
				if (!isdigit(posX[i]) && (posX[i] != '-'))
				{
					cout << posX[i] << " is not a number." << endl;
					t2 = false; // we need to check again
				}
			}
			// check to see if valid again
			if (t2) // meaning all is well
			{
				f2 = true;
			}
			else
			{
				cout << "Wrong input. Try again with an integer." << endl;
				in >> posX;
				posXLength = posX.length();
			}
		}
		stringstream ss2(posX);
		ss2 >> x;
		(s.d)->push_back(x);
		//cout << "Added " << x << endl;
		}
	return in;
}
/*
	Display the data set (print to the command-line)
*/
ostream& operator<<(ostream &out, StatisticsProcessor &s)
{
	// use get value at 
	out << "DataSet: " << endl << *(s.d) << endl;
	return out;
}
/*
	Indicate whether data set is empty.
*/
bool StatisticsProcessor::empty()
{
	return ((d->size()) == 0);
}
/*
	Clear a data set.
*/
void StatisticsProcessor::clear()
{
	delete d;
	d = new DynamicArray;
	//cout << "Just cleared everything. Now our array has: " << endl << *d << endl;
}
/*
	Get the minimum data element.
*/
int StatisticsProcessor::computeMin()
{
	return (d->getMin());
}
/*
	Get the maximum data element.
*/
int StatisticsProcessor::computeMax()
{
	return (d->getMax());
}
/*
	Get the range of the data set.
*/
int StatisticsProcessor::computeRange()
{
	return (d->getMax() - d->getMin());
}
/*
	Get the arithmetic mean of the data set.
*/
float StatisticsProcessor::computeMean()
{
	return (d->getMean());
}
/*
	Get the standard deviation of the data set.
*/
float StatisticsProcessor::computeSDev()
{
	return (d->getSDev());
}
/*
	Get the mode of the data set.
*/
int StatisticsProcessor::computeMode() const
{
	return (d->getMode());
}

/*
	Save the data set (write to a file)
*/
void StatisticsProcessor::writeData(std::string file_name)
{
	ofstream myfile;
	myfile.open(file_name);
	myfile << d->size(); // first line should contain size
	myfile << "\n";
	 
	for (int i = 0; i < (d->size()); i++)
	{
		myfile << d->getValueAtIndex(i);
		//cout << "Index: " << i << " Value: " << d->getValueAtIndex(i) << endl;
		myfile << "\n";
	}
}
