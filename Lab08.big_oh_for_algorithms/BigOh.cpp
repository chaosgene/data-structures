#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	//declare a few time points
	chrono::monotonic_clock::time_point start, finish;	
	//declare a holder for nanoseconds
	chrono::nanoseconds elapsed;
	//seed the random number generator
	srand(time(NULL));
	//For the different sizes
	for (int size = 10; size <= 100000; size = size * 10)
	{
		cout << "Testing on vector of size " << size << endl;
		//declare and initialize long variables to store the
		//accumulated time needed for each algorithm
		long sort_duration = 0;
		long binarysearch_duration = 0;
		long reverse_duration = 0;
		long stablesort_duration = 0;
	
		//For the iterations
		for (int i = 0; i < 100; i++)
		{
			//Create a vector full of random data up to size
			std::vector<int> myVec;
			for (int p = 0; p < size; p++)
			{
				int random_int = rand();
				myVec.push_back(random_int);
			}
			
			//start a timer
			start = chrono::monotonic_clock::now();
				//call sort
			std::sort(myVec.begin(), myVec.end());
			//stop the timer
			finish = chrono::monotonic_clock::now();		
			//compute elapsed time
			elapsed = chrono::duration_cast<chrono::nanoseconds>(finish-start);
			//accumulate the elapsed time into sort's time accumulator
			sort_duration = sort_duration + elapsed.count();
			
			int random_int = rand();
			//start a timer
			start = chrono::monotonic_clock::now();
				//call binary_search on a random data element
			
			std::binary_search(myVec.begin(), myVec.end(), random_int);
			//stop the timer
			finish = chrono::monotonic_clock::now();
			//compute elapsed time
			elapsed = chrono::duration_cast<chrono::nanoseconds>(finish-start);
			//accumulate the elapsed time into search's time accumlator
			binarysearch_duration = binarysearch_duration + elapsed.count();
			//empty out and re-fill the vector
			myVec.clear();
			for (int p = 0; p < size; p++)
			{
				int random_int = rand();
				myVec.push_back(random_int);
			}
			
			//start a timer
			start = chrono::monotonic_clock::now();
				//call reverse
			std::reverse(myVec.begin(), myVec.end());
			//stop the timer
			finish = chrono::monotonic_clock::now();
			//compute elapsed time
			elapsed = chrono::duration_cast<chrono::nanoseconds>(finish-start);
			//accumulate the elapsed time into reverse's time accumulator
			reverse_duration = reverse_duration + elapsed.count();

			//start a timer
			start = chrono::monotonic_clock::now();
				//call stable_sort
			std::stable_sort(myVec.begin(), myVec.end());
			//stop the timer
			finish = chrono::monotonic_clock::now();
			//compute elapsed time
			elapsed = chrono::duration_cast<chrono::nanoseconds>(finish-start);
			//accumulate the elapsed time into stable_sort's time accumulator
			stablesort_duration = stablesort_duration + elapsed.count();

		}
		//print out the average time (accumulator divided by number of trials)
		//for each of the operations (remember not to use integer division)
		cout << endl << "Sort average in nanoseconds: " << sort_duration / ((long) 100) << endl;
		cout << "Binary Search average in nanoseconds: " << binarysearch_duration / ((long) 100) << endl;
		cout << "Reverse average in nanoseconds: " << reverse_duration / ((long) 100) << endl;
		cout << "Stable Sort average in nanoseconds: " << stablesort_duration / ((long) 100) << endl << endl;
	}
	return 0;
}
