#include <string>
#include <fstream>
#include <iostream>
typedef int Element;
class DynamicArray{
	private:
		// Array of elements, since the array has to be dynamic
		// this value is a pointer to an Element
		Element* dynamicArray;
		// The number of elements currently in the array
		int arraySize;
		// The number of elements that can possibly fit in the array w/o 
        // reallocation
		int arrayCapacity;
	public:
		//Default Constructor
		DynamicArray();
		//Copy Constructor
		DynamicArray(const DynamicArray& d);
		//Explicit Value Constructor
		DynamicArray(int size, Element e);
		friend std::ostream& operator<<(std::ostream &output,
                                        const DynamicArray &d);
		DynamicArray& operator=(const DynamicArray &rhs);
		//Destructor
		~DynamicArray();
		//Add to end
		void push_back(Element e);
		//Add to front
		void push_front(Element e);
		
		//Remove from end and return
		Element pop_back();
		
		//Search, return position in array, -1 if not found
		int search(Element e);
		//Indicate whether or not the provided index is valid
		bool valid_index(int index);
		//Return size of array (num of elements currently in the array)
		int size();
		//Return capacity of array (num of elements array can currently hold)
		int capacity();
		Element getMin();
		Element getMax();
		float getMean();
		float getSDev();
		Element getMode() const;
		Element getValueAtIndex(int i);
};

