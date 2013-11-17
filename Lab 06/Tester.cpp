#include <iostream>
using namespace std;
#include "LinkedList.h"
int main()
{
	cout << "Create a default linked list..." << endl;	
	LinkedList intList;
	cout << "Inserting 13, 12, 11 in order to the front..." << endl;
	intList.insert_front(13);
	intList.insert_front(12);
	intList.insert_front(11);
	cout << "Inserting 14, 15 in order to the back..." << endl;
	intList.insert_back(14);
	intList.insert_back(15);
	cout << intList << endl;

	intList.delete_front();
	cout << "Deleted the front" << endl;
	cout << intList << endl;

	intList.delete_front();
	cout << "Deleted the front again" << endl;
	cout << intList << endl;

	intList.delete_front();
	intList.delete_front();
	intList.delete_front();
	cout << "Just emptied all." << intList << endl;

	cout << "Try to delete_front again." << endl;
	intList.delete_front();

	cout << "Repopulate linked list." << endl;
	intList.insert_front(4);
	intList.insert_front(3);
	intList.insert_front(2);
	intList.insert_front(1);
	cout << intList << endl;
	intList.delete_back();
	cout << "Deleted the back" << endl;
	cout << intList << endl;
	intList.delete_back();
	cout << "Deleted the back again" << endl;
	cout << intList << endl;
	cout << "Emptying the remainder of the list." << endl;
	
	intList.delete_back();

	intList.delete_back();


	cout << intList << endl;
	cout << "Try to delete_back again" << endl;
	intList.delete_back();

	cout << "Make a new default list." << endl;
	LinkedList list2;
	cout << "Inserted to the back 300 and 45 in order." << endl;
	list2.insert_back(300);
	list2.insert_back(45);
	cout << list2 << endl;
	
	return 0;
}
