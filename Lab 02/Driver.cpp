#include <iostream>
#include "DynamicArray.h"
#include <stdexcept> 
//define DEBUG as 1 to print debugging info, as 0 to turn it off
#define DEBUG 0
using namespace std;
int main(){
	//Call the default constructor, using the stack
	//Will be automatically destructed
	DynamicArray d;
	if(d.size() != 0) { 
		if(DEBUG) {cout << "Default constructor size is wrong." << endl;}
		return -1;
	}
	if(d.capacity() != 0) {
		if(DEBUG) {cout << "Default constructor capacity is wrong." << endl;}
		return -2;
	}
	
	if(DEBUG) {cout << "Pushing back the following values to the array:" << endl;}
	float i = 13.0;
	int j = 0;
	while(i > -1){
		d.push_back(i);
		if(DEBUG) {cout << j << ": " << i << endl;}
		i -= 0.5;
		j++;
	}
	if(d.size() != 28) {
		if(DEBUG) {cout << "Push_back does not correctly manage size." << d.size() << endl;}
		return -3;
	}
	if(d.capacity() != 32) {
		if(DEBUG) {cout << "Push_back does not correctly adjust capacity." << d.capacity() << endl;}
		return -4;
	}
	d.push_back(4.5);
	j++;
	if(DEBUG) {cout << j << ": " << 4.5 << endl;}
	if(d.search(0) != 26) {
		if(DEBUG) {cout << "Search did not return the correct index." << endl;}
		return -5;
	}
	if(d.search(4.5) != 17) {
		if(DEBUG) {cout << "Search likely did not return the first index of a given value." << endl;}
		return -6;
	}
	if(d.search(14.0) != -1) {
		if(DEBUG) {cout << "Search did not return the correct index when the value was not found." << endl;}
		return -7;
	}
	int currSize = d.size();
	int currCap = d.capacity();
	if(d.valid_index(-1)){
		if(DEBUG) {cout << "Valid index test fails for negative index." << endl;}
		return -8;
	}
	if(d.valid_index(currSize)){
		if(DEBUG) {cout << "Valid index test fails for current size. Should be false with 0-based indexing." << endl;}
		return -9;
	}
	if(d.valid_index(currCap+1)){
		if(DEBUG) {cout << "Valid index test fails for current capacity + 1." << endl;}
		return -10;
	}
	if(!d.valid_index(currSize-2)){
		if(DEBUG) {cout << "Valid index test fails when the current index is valid." << endl;}
		return -11;
	}
	float f;
	while(d.size() != 0){
		try{
			f = d.pop_back();
			if(DEBUG){cout << "Removed: " << f << endl;}
		} catch (const std::out_of_range& oor){
			if(DEBUG) {cout << "Out of range error thrown when it shouldn't have been." << endl;}
		        cout << oor.what() << endl;
			return -12;
		}
	}
	try{
		f = d.pop_back();
	} catch (const std::out_of_range& oor){
		cout<<"Passed out of range throw test." << endl;
	}
	if(currCap != d.capacity()){
		if(DEBUG) {cout << "You were not supposed to adjust the capacity down." << endl;}
		return -13;
	}
	
	//Call the explicit value constructor, using the heap
	//Will need to be explicitly destructed
	
	DynamicArray* p = new DynamicArray(12, 3.14f);
	
	
	if(p->size() != 12) {return -14;}
	if(p->capacity() != 12) {return -15;}
	
	while(p->size() != 0){
		f = p->pop_back();
		if(f != 3.14f) {
			cout << "f: " << f << endl;
			if(DEBUG){cout << "You were supposed to initialize the values in the explicit value constructor." << endl;}
			return -16;
		}
	}
	
	//Call the destructor
	delete p;
	
	return 0;
}