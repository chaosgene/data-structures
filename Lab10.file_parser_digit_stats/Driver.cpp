#include <iostream>
#include <fstream>
#include <string>
#include "LinkedLines.h"
#include <sstream>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
/*
Requirements
1: Display line
2: Display digit distribution for line
3: Display # of integer lines.
4: Display # of decimal lines.
5: Display distribution of first digit[0-9]
6: Sort and display line(s) with the greatest, nonzero count for an input collection of digits.
*/
	//const bool DEBUG = 0;
	string line;
	LinkedLines ddc;
	int firstDigitDistro[12] = {0};

	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);

	// START TIMER

	// Declare time points
	chrono::monotonic_clock::time_point start, finish;
	// Declare holder for nanosecs
	chrono::milliseconds elapsed;
	start = chrono::monotonic_clock::now();

	if (inputFile.is_open())
	{
		while (getline(inputFile, line))
		{
			if (line.empty())
				continue;			
			// Display line
			//if (DEBUG)
				//cout << line << endl; // Requirement 1
			outputFile << line << endl;

			// Create an array for each line
			int * thisLine = new int[12];
			for (int i = 0; i < 12; i++)
				thisLine[i] = 0;
			bool isFirstDigit = 1;

			// Parse through the chars
			for (char& c : line)
			{
				
				// Convert the character into an int
				int digit = c - '0';
				// Increment the index of the array
				// Offset by 2 because converting '.' -> -2
				// Index: 0  1  2 3 4 5 6 7 8 9 10 11
				// Digit: -2 -1 0 1 2 3 4 5 6 7 8  9
				// Char:  .     0 1 2 3 4 5 6 7 8  9
				thisLine[digit+2]++;
				if (isFirstDigit)
				{
					firstDigitDistro[digit+2]++;
					isFirstDigit = 0;
				}
			}
			ddc.push_front(thisLine, line);

			// Display line digit distribution
			//if (DEBUG)
				//cout << "[0-9]:  ";
			outputFile << "[0-9]:  ";
			for (int i = 2; i < 11; i++)
			{
				 // Requirement 2
				//if (DEBUG)	
					//cout << thisLine[i] << ", ";	
				outputFile << thisLine[i] << ", ";
			}
			//if (DEBUG)
				//cout << thisLine[11] << endl; // Do not end output with a ,
			outputFile << thisLine[11] << endl;
		}
	inputFile.close();
	}
	else cout << "File does not exist or cannot be opened." << endl;

	//if (DEBUG)
		//cout << "There were " << ddc.getNumIntegers() << " integer values in the data set." << endl; // Requirement 3
	outputFile << "There were " << ddc.getNumIntegers() << " integer values in the data set." << endl;
	//if (DEBUG)
		//cout << "There were " << ddc.getNumDecimals() << " decimal values in the data set." << endl; // Requirement 4
	outputFile << "There were " << ddc.getNumDecimals() << " decimal values in the data set." << endl;

	for (int i = 2; i < 11; i++)
	{
		//if (DEBUG)
			//cout << (firstDigitDistro)[i] << ", "; // Requirement 5
		outputFile << (firstDigitDistro)[i] << ", ";
	}
	//if (DEBUG)
		//cout << (firstDigitDistro)[11] << endl; // Do not end output with a ,
	outputFile << (firstDigitDistro)[11] << endl;
	outputFile.close();
	
	// Testing
	//	cout << "Test traversal." << endl;
	//	ddc.traverse();

	// Requirement 6;
	
	ifstream inPrompts("queries.txt");
	string inputStr = "";
	if (inPrompts.is_open())
	{
		while (getline(inPrompts, inputStr))
		{
			//cout << endl << "New line" << endl;
			if (inputStr == "Q")
				break;
			std::vector<int> v;
			for (char & c : inputStr)
			{
				int x = c - '0';
				v.push_back(x);
			}
			ddc.findLinesWithMostOcc(v);	
		}
	}
	finish = chrono::monotonic_clock::now();
	elapsed = chrono::duration_cast<chrono::milliseconds>(finish-start);
	long duration = elapsed.count();
	cout << "Execution time: " << duration << "ms" << endl;
	return 0;
}
