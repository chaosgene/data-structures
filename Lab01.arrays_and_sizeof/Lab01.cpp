#include <iostream>
#include "Lab01.h"
using namespace std;

int Lab01::question1a (int array[], int arraySize)
{
	int retV;
	if (array == NULL)
	{
		retV = -10000;
	}
	else
	{
	// Find the maximum integer in an array
	
		if (arraySize > 0) // Ensure the array is populated
		{
			int max = array[0]; // Set the maximum to the first element
			for (int i = 1; i < arraySize; i++) // Traverse through the array
			{
				if (array[i] > max) // Check each element if its greater than the current running maximum
				{
					max = array[i]; // Reset the maximum to the greater value
				}
			}
			retV = max;
		}
		else
		{
			retV = -10000; // If a maximum cannot be found, set the specified value
		}
	}
	return retV;
}

int Lab01::question1b (int *A, int arraySize)
{
	int retV;
	if ((A) == NULL)
	{
		retV = -10000;
	}
	else
	{
	// Find the maximum integer in an array
	
		if (arraySize > 0) // Ensure the array is populated
		{
			int max = *A; // Set the maximum to the first element
			for (int i = 1; i < arraySize; i++) // Traverse through the array
			{
				if ((*(A+i)) > max) // Check each element if its greater than the current running maximum
				{
					max = *(A+i); // Reset the maximum to the greater value
				}
			}
			retV = max;
		}
		else
		{
			retV = -10000; // If a maximum cannot be found, set the specified value
		}
	}
	return retV;
}

void Lab01::question2(int start, int finish)
{
	// Print every even number between the input bounds, exclusive
	int currentValue;
	int interval;
	interval = 1;
	if (start % 2 == 0) // If the first element is even
	{
		interval = 2;
	}
	currentValue = start + interval;
	while (currentValue < finish)
	{
		cout << currentValue << endl;
		start = currentValue;
		currentValue = start + 2;
	}
}	

int Lab01::question3(int first, int second)
{
	// Find the least common multiple of the two inputs
	int lcm;
	lcm = first;
	if ((first > 0) && (second > 0)) // Ensure inputs are positive
	{
		for (int c = 2; (lcm % second) != 0; c++) // Check if multiples of one input are divisible by the other until one is found
		{
			lcm = first * c;
		}
	}
	else
	{
		lcm = -1;
	}
	return lcm;
}

std::string Lab01::question4(std::string the_string)
{
	// Reverse the input string
	the_string = string (the_string.rbegin(), the_string.rend() );
	return the_string;
}

void Lab01::question5()
{
	// Print the numbers from 1 to 100
	// For multiples of 4, print Fizz instead of the number
	// For multiples of 7, print Buzz instead of the number
	// For multiples of 4 and 7, print FizzBuzz instead of the number
	for (int p = 1; p < 101; p++)
	{
		if ((p % 4 == 0) && (p % 7 == 0))
		{
			cout << "FizzBuzz" << endl;
		}
		else if ((p % 4) == 0)
		{
			cout << "Fizz" << endl;
		}
		else if ((p % 7) == 0)
		{
			cout << "Buzz" << endl;
		}
		else
		{
			cout << p << endl;
		}
	}
}

void Lab01::question6()
{
	int rank;
	rank = 12;
	// Print the multiplication table up to 12
	int table[rank+1][rank+1];

	// Populate the table
	for (int i = 0; i < rank+1; i++)
	{
		table[0][i] = i;
	
		for (int j = 0; j < rank+1; j++)
		{
			table[i][j] =(i*j);
		}
	
		table[i][0] = i;
	}

	// Since the upper-left corner is an X and this is a multidimensional array of ints, separately print values
	cout << "X" << "\t";
	for (int i = 1; i < rank+1; i++)
	{
		cout << i << "\t";
	}
	cout << endl;

	// Print the rest of the table
	for (int i = 1; i < rank+1; i++) // Each row
	{
		for (int j = 0; j < rank+1; j++) // Each column
		{
			cout << table[i][j] << "\t";
		
		}
		cout << endl;
	}
}

void Lab01::sizeofUse()
{
	/*
	Sizeof, when compiled, determines the sizes by bytes of a variable.
	It tell us how many bytes of memory have been allocated to store something of this type. 
	Pointers all contain 8 bytes because they are memory addresses.
	This is the same with heap-allocated arrays which relies on pointers.
	Stack-allocated arrays take up as many bytes as they have items times the space
	needed for each item.
	Therefore, sizeof is a very low-level indicator of how much memory is being used.
	Extra calculations will be necessary to find the actual number of elements in an array, for example 
	(knowing the type and amount of bytes one item of such type needs is a start). 
	*/
	cout << "sizeof int" << endl;
	int a;
	a = 5;
	
		cout << sizeof(a) << endl;

	cout << "sizeof char" << endl;
	char b;
	b = 'a';
		cout << sizeof(b) << endl;

	cout << "sizeof double" << endl;
	double c;
	c = 3.14;
		cout << sizeof(c) << endl;

	cout << "sizeof pointer (int)" << endl;
	int *pointerInt = &a;
	cout << sizeof(pointerInt) << endl;


	cout << "sizeof pointer (char)" << endl;
	char *pointerChar = &b;
	cout << sizeof(pointerChar) << endl;

	cout << "sizeof pointer (double)" << endl;
	double *pointerDouble = &c;
		cout << sizeof(pointerDouble) << endl;

	cout << "sizeof stack-allocated array (int)" << endl;
	int arrayInts[] = {1, 2, 3};
	cout << sizeof(arrayInts) << endl;

	cout << "sizeof stack-allocated array (char)" << endl;
	char arrayChars[] = {'a', 'b', 'c', 'd'};
	cout << sizeof(arrayChars) << endl;

	cout << "sizeof stack-allocated array (double)" << endl;
	double arrayDoubles[] = {1.2, 3.4};
	cout << sizeof(arrayDoubles) << endl;

	cout << "sizeof heap-allocated array (int)" << endl;
	int *arrayInts2= new int[5];
	cout << sizeof(arrayInts2) << endl;

	cout << "sizeof heap-allocated array (char)" << endl;
	char *arrayChars2= new char[5];
	cout << sizeof(arrayChars2) << endl;

	cout << "sizeof heap-allocated array (double)" << endl;
	double *arrayDoubles2 = new double[5];
	cout << sizeof(arrayDoubles2) << endl;
}

