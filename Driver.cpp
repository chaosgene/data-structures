#include <iostream>
#include <cstdlib>
#include "Lab01.h"
#define CAPACITY 20

int main(int argc, char** argv)
{
	Lab01 lab1;
	
	std::cout << std::endl <<"Testing for question 1a." << std::endl;
	{
		int *myArray = new int[CAPACITY];
		for(int i = 0; i < CAPACITY; i++)
			myArray[i] = 300+i;

		int myMax = lab1.question1a(myArray, CAPACITY);
		if(myMax != 319)
		{
			std::cerr << "Failed Question 1. ";
			std::cerr << "Standard case where passed size was the size." << std::endl;
			exit(-1);
		}
		int myMax1 = lab1.question1a(myArray, CAPACITY-5);
		if(myMax1 != 314)
		{
			std::cerr << "Failed Question 1. ";
			std::cerr << "Standard case where we are only processing part of the array." << std::endl;
			exit(-1);
		}
		myArray[0] = myMax + myArray[0];
		int myMax2 = lab1.question1a(myArray, CAPACITY);
		if(myMax2 != myArray[0])
		{
			std::cerr << "Failed Question 1. ";
			std::cerr << "Standard case where max value has been changed from first case." << std::endl;
			exit(-1);
		}
		int myMax3 = lab1.question1a(myArray,0);
		if(myMax3 != -10000)
		{
			std::cerr << "Failed Question 1. ";
			std::cerr << "Case where the size of the array is 0." << std::endl;
			exit(-1);
		}
		int myMax4 = lab1.question1a(myArray,-2);
		if(myMax4 != -10000)
		{
			std::cerr << "Failed Question 1. ";
			std::cerr << "Case where the size of the array is < 0." << std::endl;
			exit(-1);
		}
		delete[] myArray;

		myArray = nullptr;
		int myMax5 = lab1.question1a(myArray, CAPACITY);
		if(myMax5 != -10000)
		{
			std::cerr << "Failed Question 1. ";
			std::cerr << "Case where a null pointer is passed." << std::endl;
			exit(-1);
		}

		myArray = new int[CAPACITY];
		for(int i = 0; i < CAPACITY; i++)
			myArray[i] = -11000+i;
		int myMax6 = lab1.question1a(myArray, CAPACITY);
		if(myMax6 != -10981)
		{
			std::cerr << "Failed Question 1. ";
			std::cerr << "Case where the maximum value is less than -10000." << std::endl;
			exit(-1);
		}
	}
	std::cout << "QUESTION 1a OKAY" << std::endl;

	std::cout << std::endl << "Testing for question 1b." << std::endl;
	{
		int *myArray = new int[CAPACITY];
		for(int i = 0; i < CAPACITY; i++)
			myArray[i] = 300+i;

		int myMax = lab1.question1b(myArray, CAPACITY);
		if(myMax != 319)
		{
			std::cerr << "Failed Question 1. ";
			std::cerr << "Standard case where passed size was the size." << std::endl;
			exit(-1);
		}
		int myMax1 = lab1.question1b(myArray, CAPACITY-5);
		if(myMax1 != 314)
		{
			std::cerr << "Failed Question 1. ";
			std::cerr << "Standard case where we are only processing part of the array." << std::endl;
			exit(-1);
		}
		myArray[0] = myMax + myArray[0];
		int myMax2 = lab1.question1b(myArray, CAPACITY);
		if(myMax2 != myArray[0])
		{
			std::cerr << "Failed Question 1. ";
			std::cerr << "Standard case where max value has been changed from first case." << std::endl;
			exit(-1);
		}
		int myMax3 = lab1.question1b(myArray,0);
		if(myMax3 != -10000)
		{
			std::cerr << "Failed Question 1. ";
			std::cerr << "Case where the size of the array is 0." << std::endl;
			exit(-1);
		}
		int myMax4 = lab1.question1b(myArray,-2);
		if(myMax4 != -10000)
		{
			std::cerr << "Failed Question 1. ";
			std::cerr << "Case where the size of the array is < 0." << std::endl;
			exit(-1);
		}
		delete[] myArray;
		myArray = nullptr;
		int myMax5 = lab1.question1b(myArray, CAPACITY);
		if(myMax5 != -10000)
		{
			std::cerr << "Failed Question 1. ";
			std::cerr << "Case where a null pointer is passed." << std::endl;
			exit(-1);
		}
		myArray = new int[CAPACITY];
		for(int i = 0; i < CAPACITY; i++)
			myArray[i] = -11000+i;
		int myMax6 = lab1.question1b(myArray, CAPACITY);
		if(myMax6 != -10981)
		{
			std::cerr << "Failed Question 1. ";
			std::cerr << "Case where the maximum value is less than -10000." << std::endl;
			exit(-1);
		}
	}
	std::cout << "QUESTION 1b OKAY" << std::endl;

	std::cout << std::endl << "Testing for question 2." << std::endl;
	{
		//Even even (numbers printed)
		std::cout << "Even numbers between 0 and 20" << std::endl;
		lab1.question2(0,20);
		//Even even (nothing printed)
		std::cout << "Even numbers between 0 and 2" << std::endl;
		lab1.question2(0,2);

		//Odd even (numbers printed)
		std::cout << std::endl << "Even numbers between 1 and 10" << std::endl;
		lab1.question2(1,10);
		//Odd even (nothing printed)
		std::cout << std::endl << "Even numbers between 1 and 2" << std::endl;
		lab1.question2(1,2);

		//Even odd (numbers printed)
		std::cout << std::endl << "Even numbers between -2 and 2" << std::endl;
		lab1.question2(-2,2);
		//Even odd (nothing printed)
		std::cout << std::endl << "Even numbers between -6 and -4" << std::endl;
		lab1.question2(-6,-4);

		//Odd odd (numbers printed)
		std::cout << std::endl << "Even numbers between -5  and 5" << std::endl;
		lab1.question2(-5,5);
		//Odd odd (nothing printed)
		std::cout << std::endl << "Even numbers between -3 and -3" << std::endl;
		lab1.question2(-3,-3);

		//When start is greater than finish
		std::cout << std::endl << "Even numbers between 10 and -10" << std::endl;
		lab1.question2(10,-10);
	}
	//You can verify whether or not question 2 is correct by commenting
	//out everything but the test for section 2, running your code using
	//    ./lab1 > question2.txt
	//Then you can perform a diff with the output q2.txt provided on blackboard

	std::cout << std::endl << "Testing for question 3." << std::endl;
	{
		int res1 = lab1.question3(5,15);
		if(res1 != 15)
		{
			std::cerr << "Failed question 3, when B is a multiple of A" << std::endl;
			exit(-3);
		}
		int res2 = lab1.question3(15,5);
		if(res2 != 15)
		{
			std::cerr << "Failed question 3, when A is a multiple of B" << std::endl;
			exit(-3);
		}
		int res3 = lab1.question3(6,4);
		if(res3 != 12)
		{
			std::cerr << "Failed question 3, when multiple is distinct" << std::endl;
			exit(-3);
		}
		int res4 = lab1.question3(3,3);
		if(res4 != 3)
		{
			std::cerr << "Failed question 3, when A equals B" << std::endl;
			exit(-3);
		}
		int res5 = lab1.question3(0,3);
		if(res5 != -1)
		{
			std::cerr << "Failed question 3, when A not viable" << std::endl;
			exit(-3);
		}
		int res6 = lab1.question3(4,-1);
		if(res6 != -1)
		{
			std::cerr << "Failed question 3, when B not viable" << std::endl;
			exit(-3);
		}
		int res7 = lab1.question3(-1,0);
		if(res7 != -1)
		{
			std::cerr << "Failed question 3, when A and B not viable" << std::endl;
			exit(-3);
		}
	}
	std::cout << "QUESTION 3 OKAY" << std::endl;

	std::cout << std::endl << "Testing for question 4." << std::endl;
	{
		std::string reverse, reverse1, reverse2;
		std::string forward = "forward";
		reverse = lab1.question4(forward);
		if(0 != reverse.compare("drawrof"))
		{
			std::cerr << "Failed question 4 on forward" << std::endl;
			exit(-4);
		}
		reverse1 = lab1.question4("");
		if(!reverse1.empty())
		{
			std::cerr << "Failed question 4 on empty string" << std::endl;
			exit(-4);
		}
		std::string spaces = "this string has spaces";
		reverse2 = lab1.question4("secaps sah gnirts siht");
		if(0 != reverse2.compare(spaces))
		{
			std::cerr << "Failed question 4 with spaces" << std::endl;	
			exit(-4);
		}
	}
	std::cout << "QUESTION 4 OKAY" << std::endl;


	std::cout << std::endl << "Testing for question 5." << std::endl;
	{
		lab1.question5();
	}
	//You can verify whether or not question 5 is correct by commenting
	//out everything but the test for question 5, running your code using
	//    ./lab1 > question5.txt
	//Then you can perform a diff with the output q5.txt provided on blackboard

	std::cout << std::endl << "Testing for question 6." << std::endl;
	{
		lab1.question6();
	}
	//You can verify whether or not question 6 is correct by commenting
	//out everything but the test for question 6, running your code using
	//    ./lab1 > question6.txt
	//Then you can perform a diff with the output q6.txt provided on blackboard

	std::cout << std::endl << "Output for the investigation of sizeof." << std::endl;
	{
		lab1.sizeofUse();
	}


}
