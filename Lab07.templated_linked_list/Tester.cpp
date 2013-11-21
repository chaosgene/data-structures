#include "LinkedList.h"
#include <iostream>
#include "Random.h"

int main()
{
	cout << "Let's try to do a comprehensive test to our doubly-linked and templated list." << endl;
	cout << "TEST DOUBLY-LINKEDNESS AND BASIC FUNCTION MEMBERS." << endl;
	LinkedList<char> l;
	cout << "Here's our default-ly constructed linked list using type char: " << endl;
	l.print();
	cout << "Let's insert a-d to the front." <<endl;
	l.insert_front('a');
	l.insert_front('b');
	l.insert_front('c');
	l.insert_front('d');
	l.print();
	cout << "Let's add v-z to the back." <<endl;
	l.insert_back('v');
	l.insert_back('w');
	l.insert_back('x');
	l.insert_back('y');
	l.insert_back('z');
	l.print();
	cout << "Let's delete the last node." << endl;
	l.delete_back();
	l.print();
	cout << "Let's delete the first node." << endl;
	l.delete_front();
	l.print();

	cout << "NOW TO TEST THE EXPLICIT COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR AGAINST SHALLOW COPIES!" << endl;
	cout << "Now test the copy constructor to make a COPY." << endl;
	LinkedList<char> l2(l);
	l2.print();

	cout << "Delete everything from the old list using delete_back." << endl;
	cout << "NOTE: We are calling delete_back 100 times. (test for what happens when delete_back gets called on an empty linked list." << endl;
	for (int i = 0; i < 100; i++)
	{
		l.delete_back();
	}

	cout << "Here's what the original looks like." << endl;
	l.print();
	cout << "Is original empty? " << endl;
	cout << l.empty() << endl;
	cout << "Has COPY changed?" << endl;
	l2.print();
	cout << "Is COPY empty?" << endl;
	cout << l2.empty() << endl;
	cout << "Let's test the assignment operator, assigning a new ASSIGNEDLIST to values from the COPY." << endl;
	LinkedList<char> l3;
	l3 = l2;
	l3.print();

	cout << "Delete everything from the COPY using delete_front 100 times. (test for delete_front on empty linked list)" << endl;
	for (int i = 0; i < 100; i++)
	{
		l2.delete_front();
	}
	cout << "Here's what COPY looks like now: " << endl;
	l2.print();
	cout << "Is COPY empty?" << endl;
	cout << l2.empty() << endl;

	cout << "Has ASSIGNEDLIST changed?" << endl;
	l3.print();
	cout << "Is ASSIGNEDLIST empty?" << endl;
	cout << l3.empty() << endl;

	cout << "NOW TEST TEMPLATED-ness for a class. Use the Random class from the tester for Lab06" << endl;
	cout << "Let's make a new linked list for the Random class." << endl;
	LinkedList<Random> l4;
	l4.insert_front(Random());
	cout << "We've added a Random object to the linked list." << endl;
	l4.print();

	cout << "Now we make sure the copy constructor works. Instead of tediously  deleting from the original, pay careful attention to the memory addresses to realize the data is being stored in different memory locations." << endl;
	LinkedList<Random> l5(l4);
	cout << "Here's our copy: " << endl;
	l5.print();

	cout << "Now let's test the assignment operator. Pay attention to the memory addresses again." << endl;
	LinkedList<Random> l6;
	l6 = l4;
	cout << "Here's an assigned linked list to the values of the original Random node linked list." << endl;
	l6.print();

	cout << endl << endl << endl << "Let's insert the code for the tester for Lab06 in here just to be extra-safe." << endl;
	srand(time(NULL));
		
	//Initialize the first linked list
	LinkedList<Random> l7;

	//Verify it was initialized empty
	if(!l7.empty()){
		cout << "Empty list is not empty." << endl; 
	} else {
		cout << "Passed the empty list as default constructor test." << endl;
	}
	cout << "----------------------------------" << endl;

	//Call the copy constructor on the empty list to create a second empty list
	LinkedList<Random> l8 = l7;

	//Verify the copied list is empty
	if(!l8.empty()){
		cout << "Empty list is not empty when using copy constructor." << endl;
	} else {
		cout << "Passed the empty list as a copy constructor test." << endl;
	}

	cout << "----------------------------------" << endl;

	//Add something to list 1
	cout << "Adding something to the front of the first list" << endl;
	cout << "..." << endl;
	l7.insert_front(Random());

	cout << "The following is the first list:" << endl;
	l7.print();

	cout << "The following is the second list:" << endl;
	l8.print();

	cout << "----------------------------------" << endl;


	//Add something to the back of list 1
	cout << "Adding something to the back  of the first list" << endl;
	cout << "..." << endl;
	l7.insert_back(Random());

	cout << "The following is the first list now:" << endl;
	l7.print();

	cout << "The following is the second list now:" << endl;
	l8.print();

	cout << "----------------------------------" << endl;

	cout << "----------------------------------" << endl;

	//Add something to the front of list 2
	cout << "The second list (0):" << endl;
	l8.print();

	cout << "Adding something to the back of the second list" << endl;
	cout << "..." << endl;
	l8.insert_back(Random());

	cout << "The second list (1):" << endl;
	l8.print();

	cout << "Adding something to the back of the second list" << endl;
	cout << "..." << endl;	
	l8.insert_back(Random());

	cout << "The second list (2):" << endl;
	l8.print();

	cout << "Adding something to the front of the second list" << endl;
	cout << "..." << endl;
	l8.insert_front(Random());

	cout << "The second list (3):" << endl;
	l8.print();

	cout << "----------------------------------" << endl;

	cout << "----------------------------------" << endl;
		
	cout << "----------------------------------" << endl;

	cout << "Commencing stress test:" << endl;

	LinkedList<Random> l9;

	int insertions=0, deletions=0, frontops=0, backops=0;

	int numops = rand()%1000000;


	int val;

	clock_t finish, start = clock();

	while( numops > (insertions + deletions)){
		val = rand();

		if(val%4==0){
			l9.insert_front(Random());	
			insertions++;
			frontops++;
		} else if (val%4 == 1){
			l9.insert_back(Random());
			insertions++;
			backops++;
		} else if (val%4 == 2){
			l9.delete_front();
			deletions++;
			frontops++;
		} else {
			l9.delete_back();
			deletions++;
			backops++;
		}
	}

	finish = clock();

	cout << "Performed " << insertions << " insertions and " << deletions << " deletions" << endl;
	cout << "\t " << 100.0f*((float)frontops/(float)numops) << "\% at the front " << endl;
	cout << "\t " << 100.0f*((float)backops/(float)numops) << "\% at the back" << endl;

	cout << endl << "This took " << ((float)finish - (float)start) / (float)CLOCKS_PER_SEC;
	cout << " seconds" << endl;

	cout << "Note to self: do a valgrind --tool=memcheck ./tester" << endl;

	cout << endl << endl << "Let's do some edge test cases here." << endl;
	LinkedList<int> intlist;
	cout << "Here's an empty linked list of ints" << endl;
	intlist.print();
	LinkedList<int> intlistcopy(intlist);
	cout << "Here's a copy of that empty linked list of ints." << endl;
	intlistcopy.print();
	cout << "How do we make sure these two are not the same linked list?" << endl;
	cout << "Here's the address of the original empty linked list of ints: " << &intlist << endl;
	cout << "Here's the address of the copy of the empty linked list of ints: " << &intlistcopy << endl;

	/*
	// The stress test suffices for inserting and deleting many times but here is a test for memory inadequacy that results in Killed
	while(true)
		intlist.insert_back(100);
	*/
	return 0;
}

