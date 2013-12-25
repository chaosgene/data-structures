#include <iostream>
#include "DynamicArray.h"
#include <cstring>
#include <stdexcept> 

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
	for (int i = 0; i < arraySize; i++) {
		dynamicArray[i] = e;
	}
}

DynamicArray::~DynamicArray() {
	delete [] dynamicArray;
}

void DynamicArray::push_back(Element e) {
	if (arraySize == arrayCapacity) {
    	// Update private variables
		if (arrayCapacity == 0) {
			arrayCapacity += 2;
		} else {
			arrayCapacity *= 2;
		}
		Element* newArray = new Element[arrayCapacity]; // Make a new array
		for (int i = 0; i < arraySize; i++) {
            newArray[i] = dynamicArray[i]; // Copy over old data
		}
		delete [] dynamicArray; // Remove the old array (prevent memory leak)
		dynamicArray = newArray;
	} else if (arraySize < arrayCapacity) {
		dynamicArray[arraySize] = e; 
        	arraySize += 1;
	}
}

void DynamicArray::push_front(Element e) {
	Element* newArray = new Element[arrayCapacity+1]; // Make a new array
	newArray[0] = e; // Set the first element to the input
	arrayCapacity+=1;
	for (int i = 1; i <= (arrayCapacity); i++) {
		newArray[i] = dynamicArray[i-1];
	}
	delete [] dynamicArray;	
	dynamicArray = newArray;
	arraySize+=1;
	arrayCapacity+=1;
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
	// An index is invalid if it is negative or too large
}

int DynamicArray::size() {
	return arraySize;
}

int DynamicArray::capacity() {
	return arrayCapacity;
}
