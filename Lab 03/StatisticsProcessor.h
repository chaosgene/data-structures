#ifndef STATISTICS_PROCESSOR_H
#define STATISTICS_PROCESSOR_H
 
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "DynamicArray.h"

class StatisticsProcessor{
	private:
		//Add your private data members and functions here
		DynamicArray *d; //DynamicArray dataSet collection of data items
		
	public:
		// Default constructor
		StatisticsProcessor();

		// Copy constructor
		explicit StatisticsProcessor(const StatisticsProcessor &s);
		
		// Assignment operator
		StatisticsProcessor& operator=(const StatisticsProcessor &rhs);
		
		// Destructor
		~StatisticsProcessor();
		
		void loadData(std::string file_name);
		friend std::istream& operator>>(std::istream &in, StatisticsProcessor &s);
		
		bool empty();
		void clear();
		int computeMin();
		int computeMax();
		float computeMean();
		int computeRange();
		float computeSDev();
		int computeMode() const;
		friend std::ostream& operator<<(std::ostream &out, StatisticsProcessor &s);
		void writeData(std::string file_name);
		
		
};

#endif //STATISTICS_PROCESSOR_H
