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
/*
	cout << "Search for 45 in this linked list..." << endl;
	cout << list2.search(45) << endl;
	
	cout << "Search for 300 in this linked list..." << endl;
	cout << list2.search(300) << endl;

	cout << "Add the value 5123 after the first node containing 300..." << endl;
	list2.insert_after(5123, list2.search(300));
	cout << list2;

	cout << "Add the value 650  after the first node containing 5123..." << endl;
	list2.insert_after(650, list2.search(5123));
	cout << list2;

	cout << "Use insert_at to add 919 after the first variable..." << endl;
	list2.insert_after(919, nullptr);
	cout << list2;
	
	cout << "Use insert_at to add 1000000 after the last variable which should contain 45..." << endl;
	list2.insert_after(1000000, list2.search(45));
	cout << list2;

	cout << "Search for 1234 in this linked list..." << endl;
	cout << list2.search(1234) << endl;

	cout << "Let's delete the node after 919..." << endl;
	list2.delete_after(list2.search(919));
	cout << list2;

	cout << "Let's delete the node after 919..." << endl;
	list2.delete_after(list2.search(919));
	cout << list2;
		
	cout << "Let's delete the node after 919..." << endl;
	list2.delete_after(list2.search(919));
	cout << list2;
	
	cout << "Let's delete the node after 919..." << endl;
	list2.delete_after(list2.search(919));
	cout << list2;
	
	cout << "Let's delete the node after 919..." << endl;
	list2.delete_after(list2.search(919));
	cout << list2;
	
	cout << "Let's delete the node after 919..." << endl;
	list2.delete_after(list2.search(919));
	cout << list2;
	
	cout << "Let's delete the node after nullptr..." << endl;
	list2.delete_after(nullptr);
	cout << list2;

	cout << "Let's use delete at to delete the first node." << endl;
	list2.delete_at(list2.search(919));
	cout << list2;

	cout << "Test the overloaded input operator."  << endl;
	LinkedList list3;
	cin >> list3;
	
	cout << list3 << endl;
	
	cout << "Let's insert a 5 where you entered a 4, a rerouting." << endl;
	cout << "Here's where you found the 4: " << list3.search(4) << endl;
	list3.insert_at(5, list3.search(4));
	cout << list3 << endl;

	cout << "Let's test the delete_at method." << endl;
	LinkedList list4;
	for (int i = 10; i <= 100; i+=10)
	{
		list4.insert_back(i);
	}
	cout << list4 << endl;
	
	cout << "Let's try to delete 40." << endl;
	list4.delete_at(list4.search(40));
	cout << list4 << endl;

	cout << "Let's try to delete 100." << endl;
	list4.delete_at(list4.search(100));
	cout << list4 << endl;

	cout << "Let's try to delete 10." << endl;
	list4.delete_at(list4.search(10));
	cout << list4 << endl;
*/
	return 0;
}
