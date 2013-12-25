#include <iostream>
#include "DynamicArray.h"
#include <cstring>
#include <stdexcept> 
#include <math.h> 

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
	}
	else if (arraySize < arrayCapacity) {
		dynamicArray[arraySize] = e; // With x items are in the array, the new item has an index of x
		arraySize += 1;
	}
}

void DynamicArray::push_front(Element e) {
	Element* newArray = new Element[arrayCapacity+1]; // Make a new array of x+1 capacity
	newArray[0] = e; // Set the first element to the input
	for (int i = 1; i < arrayCapacity; i++) {
		newArray[i] = dynamicArray[i];
	}
	delete [] dynamicArray;
	dynamicArray = newArray;
}

Element DynamicArray::pop_back() {
	if (arraySize <= 0)	{
		throw std::out_of_range ("Out of range.");
	}
	Element returnVal = dynamicArray[arraySize-1]; // Store the last value
	Element* newArray = new Element[arrayCapacity]; // The updated array will have the original capacity
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

int DynamicArray::size() {
	return arraySize;
}

int DynamicArray::capacity() {
	return arrayCapacity;
}

Element DynamicArray::getMin() {
	Element minVal;
	if (arraySize == 0) {
		return 0;
	}
	minVal = dynamicArray[0];
	//cout << "min first set to " << minVal << endl;
	for (int i = 1; i < arraySize; i++)	{
		//cout << "\t Checking: " << dynamicArray[i] << endl;
		if (dynamicArray[i] < minVal) {
			//cout << "This is less than" << minVal << endl;
			minVal = dynamicArray[i];
		}
	}
	return minVal;
}

Element DynamicArray::getMax() {
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

float DynamicArray::getMean() {
	if (arraySize == 0)	{
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < arraySize; i++)	{
		sum += dynamicArray[i];
	}
	return ((float)sum / (float)arraySize);
}

float DynamicArray::getSDev() {
	if (arraySize == 0)	{
		return 0;
	}
	float mean = getMean();
	float difference;
	float sum;
	for (int i = 0; i < arraySize; i++)	{
		difference = ((float)dynamicArray[i]) - mean;
		sum += pow(difference, 2);
	}
	return pow((sum / arraySize), 0.5);
}

int DynamicArray::getMode() const {
	if (arraySize == 0) {
		return 0;
	}
	int mode = dynamicArray[0];
	int modeOcc = 0;
	for (int i = 0; i < arraySize; i++)	{
		// Going through each element of the array
		int possibleMode = dynamicArray[i];
		int numOcc = 0;
		for (int j = 0; j < arraySize; j++)	{
			if (dynamicArray[i] == possibleMode) {
				numOcc+=1;
			}
		}
		if (numOcc > modeOcc) {
			mode = possibleMode;
		}
		else if (numOcc == modeOcc) {
			if (possibleMode < mode) {
				mode = possibleMode;
			}
		}
	}
	return mode;
}

Element DynamicArray::getValueAtIndex(int k) {
	return *(dynamicArray+k);
}
