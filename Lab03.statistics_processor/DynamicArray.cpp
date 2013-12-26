#include <iostream>
#include "DynamicArray.h"
#include <stdexcept> 
#include <math.h> 
#include <map>

using namespace std;

DynamicArray::DynamicArray() {
	dynamicArray = nullptr;
	arraySize = 0;
	arrayCapacity = 0;
}

DynamicArray::DynamicArray(int size, Element e) {
	arraySize = size;
	arrayCapacity = size;
	dynamicArray = new Element[arrayCapacity];
	
	for (int i = 0; i < arraySize; i++)	{
		dynamicArray[i] = e;
	}
}

DynamicArray::DynamicArray(const DynamicArray& d) {
	arraySize = d.arraySize;
	arrayCapacity = d.arrayCapacity;
	cout << "Creating a deeper copy of a dynamic array" << endl;
	dynamicArray = new Element[arrayCapacity];
	for (int i = 0; i < arrayCapacity; i++)	{
		dynamicArray[i] = d.dynamicArray[i]; // Copy over old data
	}
}

ostream& operator<<( ostream &output, const DynamicArray &d) { 
	 for (int i = 0; i < d.arraySize; i++) {
		cout << d.dynamicArray[i] << "\t";
		if ((i + 1) % 4==0)	{
			cout << endl;
		}
	 }
	 output << endl << "Array Size: " << d.arraySize << " Array Capacity: "
        << d.arrayCapacity << endl;
	 return output;            
}

DynamicArray::~DynamicArray() {
	cout << "Deconstructing everything" << endl;
	delete [] dynamicArray;
	cout << "deconstructed success!" << endl;
}

void DynamicArray::push_back(Element e) {
	if (arraySize == arrayCapacity) {
		// Update private variables
		if (arrayCapacity == 0)	{
			arrayCapacity += 2;
		} else {
			arrayCapacity *= 2;
		}
		Element* newArray = new Element[arrayCapacity]; // Make a new array
		for (int i = 0; i < arraySize; i++)	{
			newArray[i] = dynamicArray[i]; // Copy over old data
		}
		delete [] dynamicArray; // Remove the old array (prevent memory leak)
		dynamicArray = newArray;
        dynamicArray[arraySize] = e;
        arraySize += 1;
	} else if (arraySize < arrayCapacity) {
		dynamicArray[arraySize] = e; 
		arraySize += 1;
	}
}

void DynamicArray::push_front(Element e) {
	Element* newArray = new Element[arrayCapacity+1]; 
	newArray[0] = e; // Set the first element to the input
	for (int i = 1; i <= arrayCapacity; i++) {
		newArray[i] = dynamicArray[i-1];
	}
	delete [] dynamicArray;
	dynamicArray = newArray;
    arraySize++;
    arrayCapacity++;
}

Element DynamicArray::pop_back() {
	if (arraySize <= 0)	{
		throw std::out_of_range ("Out of range.");
	}
	Element returnVal = dynamicArray[arraySize-1]; // Store the last value
	Element* newArray = new Element[arrayCapacity];
	for (int i = 0; i < (arraySize-1); i++)	{
			newArray[i] = dynamicArray[i];
	}
	// Update private variables
	arraySize -= 1;
	delete [] dynamicArray;
	dynamicArray = newArray;
	return returnVal;
}

int DynamicArray::search(Element e) {
	bool found = false;
	int returnVal;
	returnVal = -1;
	for (int i = 0; ((i < arraySize) && (!found)); i++) {
		if (dynamicArray[i] == e) {
			returnVal = i;
			found = true;
		}
	}
	return returnVal;
}

bool DynamicArray::valid_index(int index) {
	return ((index >= 0) && (index < arraySize));
}

int DynamicArray::size() const {
	return arraySize;
}

int DynamicArray::capacity() const {
	return arrayCapacity;
}

Element DynamicArray::getMin() const {
	Element minVal;
	if (arraySize == 0) {
		return 0;
	}
	minVal = dynamicArray[0];
	cout << "min first set to " << minVal << endl;
	for (int i = 0; i < arraySize; i++)	{
		cout << "\t Checking: " << dynamicArray[i] << endl;
		if (dynamicArray[i] < minVal) {
			cout << "This is less than" << minVal << endl;
			minVal = dynamicArray[i];
		}
	}
	return minVal;
}

Element DynamicArray::getMax() const {
	Element maxVal;
	if (arraySize == 0)	{
		return 0;
	}
	maxVal = dynamicArray[0];
	//cout << "max first set to " << maxVal << endl;
	for (int i = 1; i < arraySize; i++) {
		//cout << "\t Checking: " << dynamicArray[i] << endl;
		if (dynamicArray[i] > maxVal) {
			//cout << "This is more than" << maxVal << endl;
			maxVal = dynamicArray[i];
		}
	}
	return maxVal;
}

float DynamicArray::getMean() const {
	if (arraySize == 0)	{
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < arraySize; i++)	{
		sum += dynamicArray[i];
	}
	return ((float)sum / (float)arraySize);
}

float DynamicArray::getSDev() const {
	if (arraySize == 0)	{
		return 0;
	}
	float mean = getMean();
    //cout << "Mean: " << mean << endl;
	float difference;
	float sum;
	for (int i = 0; i < arraySize; i++)	{
        //cout << "Difference between " << dynamicArray[i] << " and " << mean << endl;
		difference = ((float)dynamicArray[i]) - mean;
        //cout << "is " << difference << endl;
		sum += pow(difference, 2);
        //cout << "added " << pow(difference, 2) << endl;
	}
	return pow((sum / arraySize), 0.5);
}

int DynamicArray::getMode() const {
	if (arraySize == 0) {
		return 0;
	}
    // Create an array of size getMax()
    Element size = getMax();
    Element counts[size+1];
    for (int i = 0; i < size+1; ++i) {
        counts[i] = 0;
    }
    //cout << "Created new array of counts." << endl;
    //cout << "Highest index in counts is " << size << endl;
    for (int i = 0; i < arraySize; ++i) {
        //cout << "Looking at " << dynamicArray[i] << endl;
        counts[dynamicArray[i]]++;
        //cout << "incremented counts index " << dynamicArray[i] << endl;
        //cout << "counter for that occurrence now: " << counts[dynamicArray[i]]
        //<< endl;
    }
    int highestCount = counts[0];
    int mode = -1;
    for (int i = 0; i < size + 1; ++i) {
        if (counts[i] > highestCount) {
            highestCount = counts[i];
            mode = i;
        }
    }
    //delete [] counts;
	return mode;
}

Element DynamicArray::getValueAtIndex(int k) {
	return *(dynamicArray+k);
}
