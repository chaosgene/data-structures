#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
	cout << endl << ">>>>> CONSTRUCTOR <<<<<" << endl;
	BinaryTree bt;
	cout << "Created a default binary tree. Here is a graphical representation." << endl;
	bt.visualize();

	cout << endl << ">>>>> EMPTY() <<<<<" << endl;
	cout << "Is the default binary tree empty? " << bt.empty() << endl;
	bt.BSTinsert(3);
	cout << "After adding a value to the binary tree, is it still empty? " << bt.empty() << endl;
	bt.remove(3);
	cout << "After removing that value from the binary tree, is it empty? " << bt.empty() << endl;

	cout << endl << ">>>>> HEIGHT() <<<<<" << endl;
	cout << "What's the height of the binary tree? " << bt.height() << endl;
	bt.insert(30);
	cout << "After adding a value to the binary tree, what is the new height: " << bt.height() << endl;
	bt.BSTinsert(20);
	bt.BSTinsert(40);
	bt.BSTinsert(10);
	bt.BSTinsert(25);
	bt.BSTinsert(35);
	bt.BSTinsert(80);
	cout << "Inserted 20, 40, 10, 25, 35, 80 to the binary tree. What is the new height? " << bt.height() << endl;
	cout << "To verify, here is a graphical representation." << endl;
	bt.visualize();
	cout << "Make a new binary tree and use insert() to put on the numbers from 0-9000." << endl;
	BinaryTree btBig;
	for (int i = 0; i < 9000; i++)
		btBig.insert(i);
	cout << "What's the height of the big binary tree?" << btBig.height() << endl;

	cout << endl << ">>>>> TRAVERSALS <<<<<" << endl;
	bt.pre_order();
	bt.in_order();
	bt.post_order();
	cout << "Try traversals on an empty binary tree." << endl;
	BinaryTree btEmpty;
	btEmpty.pre_order();
	btEmpty.in_order();
	btEmpty.post_order();

	cout << endl << ">>>>> IS_BST() <<<<<" << endl;
	cout << "Does the binary tree possess binary search tree properties? " << bt.is_BST() << endl;
	cout << "Does an empty binary tree possess binary search tree properties? " << btEmpty.is_BST() << endl;
	cout << "Since the previous adding of elements to the binary tree preserves the binary search tree property, another method called insert() is defined." << endl;
	cout << "Using insert to add elements 100 to 86 to the binary tree." << endl;
	for (int i = 100; i > 85; i--)
		btEmpty.insert(i);
	cout << "Here's a visual." << endl;
	btEmpty.visualize();
	cout << "Does this binary tree have BST properties? " << btEmpty.is_BST() << endl;
	for (int i = 100; i > 87; i--)
		btEmpty.remove(i);
	cout << "What about the smallest case that violates the BST properties?" << endl;
	btEmpty.visualize();
	cout << "Does this binary tree have BST properties? " << btEmpty.is_BST() << endl;
	cout << "What if these items were swapped?" << endl;
	BinaryTree btSwap;
	btSwap.insert(86);
	btSwap.insert(87);
	btSwap.visualize();
	cout << "Does this binary tree have BST properties? " << btSwap.is_BST() << endl;
	cout << endl << ">>>>> SEARCH(int DATA) <<<<<" << endl;
	cout << "The binary tree used resembles: " << endl;
	bt.visualize();
	cout << "Search if 30 is in the tree. " << bt.search(30) << endl;
	cout << "Search if 80 is in the tree. " << bt.search(80) << endl;
	cout << "Search if 5 is in the tree. " << bt.search(5) << endl;

	cout << endl << ">>>>> FIND(int DATA) <<<<<" << endl;
	cout << "The binary tree used resembles: " << endl;
	bt.visualize();
	cout << "Find 30: " << bt.find(30) << endl;
	cout << "Find 20: " << bt.find(20) << endl;
	cout << "Find 40: " << bt.find(40) << endl;
	cout << "Find 2121: " << bt.find(2121) << endl;
	cout << "Find 10: " << bt.find(10) << endl;
	cout << "Find 25: " << bt.find(25) << endl;
	cout << "Find 35: " << bt.find(35) << endl;
	cout << "Find 80: " << bt.find(80) << endl;
	cout << "Find 9001: " << bt.find(9001) << endl;

	cout << endl << ">>> IS_BALANCED() <<<<<" << endl;
	cout << "Is the tree balanced: " << bt.is_balanced() << endl;
	btEmpty.insert(314);
	cout << "And this one? " << endl;
	btEmpty.visualize();
	cout << "Is this tree balanced: " << btEmpty.is_balanced() << endl;
	cout << "And this one? " << endl;
	btSwap.visualize();
	cout << "Is this tree balanced: " << btSwap.is_balanced() << endl;
		
	cout << endl << ">>> DELETE(int DATA) <<<<<" << endl;
	cout << "Delete 80" << endl;
	bt.remove(80);
	bt.visualize();
	cout << "Is it now empty? " << bt.empty() << endl;
	cout << "Does it possess binary tree properties? " << bt.is_BST() << endl;
	cout << "Binary tree height: " << bt.height() << endl;
	cout << "Is the tree balanced: " << bt.is_balanced() << endl;

	cout << "Delete 35" << endl;
	bt.remove(35);
	bt.visualize();
	cout << "Is it now empty? " << bt.empty() << endl;
	cout << "Does it possess binary tree properties? " << bt.is_BST() << endl;
	cout << "Binary tree height: " << bt.height() << endl;
	cout << "Is the tree balanced: " << bt.is_balanced() << endl;

	cout << endl << "Delete 25" << endl;
	bt.remove(25);
	bt.visualize();
	cout << "Is it now empty? " << bt.empty() << endl;
	cout << "Does it possess binary tree properties? " << bt.is_BST() << endl;
	cout << "Binary tree height: " << bt.height() << endl;
	cout << "Is the tree balanced: " << bt.is_balanced() << endl;
	
	cout << endl << "Delete 10" << endl;
	bt.remove(10);
	bt.visualize();
	cout << "Is it now empty? " << bt.empty() << endl;
	cout << "Does it possess binary tree properties? " << bt.is_BST() << endl;
	cout << "Binary tree height: " << bt.height() << endl;
	cout << "Is the tree balanced: " << bt.is_balanced() << endl;
	
	cout << endl << "Delete 40" << endl;
	bt.remove(40);
	bt.visualize();
	cout << "Is it now empty? " << bt.empty() << endl;
	cout << "Does it possess binary tree properties? " << bt.is_BST() << endl;
	cout << "Binary tree height: " << bt.height() << endl;
	cout << "Is the tree balanced: " << bt.is_balanced() << endl;

	cout << endl << "Delete 20" << endl;
	bt.remove(20);
	bt.visualize();
	cout << "Is it now empty? " << bt.empty() << endl;
	cout << "Does it possess binary tree properties? " << bt.is_BST() << endl;
	cout << "Binary tree height: " << bt.height() << endl;
	cout << "Is the tree balanced: " << bt.is_balanced() << endl;

	cout << endl <<  "Delete 30" << endl;
	bt.remove(30);
	bt.visualize();
	cout << "Is it now empty? " << bt.empty() << endl;
	cout << "Does it possess binary tree properties? " << bt.is_BST() << endl;
	cout << "Binary tree height: " << bt.height() << endl;
	cout << "Is the tree balanced: " << bt.is_balanced() << endl;

	cout << endl << ">>>>> FILE I/O <<<<<" << endl;
	bt.BSTinsert(32);
	bt.BSTinsert(10);
	bt.BSTinsert(42);
	bt.BSTinsert(13);
	bt.BSTinsert(35);
	bt.BSTinsert(49);
	cout << "Added 32, 10, 42, 13, 35, 49." << endl;
	bt.pre_order();
	bt.in_order();
	bt.post_order();
	bt.write("out");
	cout << "What was just written to the file: " << endl;
	bt.visualize();		
	
	BinaryTree bt1;	
	bt1.read("out");
	bt1.pre_order();
	bt1.in_order();
	bt1.post_order();
	cout << "Here's what was read back from the file: " << endl;
	bt1.visualize();
	
	cout << endl << ">>>>> COPY CONSTRUCTOR <<<<<" << endl;
	BinaryTree btCopy(bt1);
	cout << "Here is a copy of the tree we read from the file." << endl;
	btCopy.visualize();
	btCopy.pre_order();
	
	cout << endl << ">>>>> ASSIGNMENT OPERATOR <<<<<" << endl;
	BinaryTree btAssigned;
	btAssigned = btCopy;
	cout << "Here is yet another binary tree assigned to the COPY made earlier." << endl;
	btAssigned.visualize();
	btAssigned.pre_order();	
	
	cout << endl << ">>>>> DUPLICATE VALUES <<<<<" << endl;
	cout << "Try to make a binary tree of duplicate values." << endl;
	BinaryTree binDup;
	binDup.BSTinsert(30);
	binDup.BSTinsert(30);
	binDup.visualize();
	binDup.remove(30);
	cout << "Remove 30." << endl;
	binDup.visualize();

	cout << endl << ">>>>> IS_SYMMETRIC() <<<<<" << endl;
	BinaryTree btSymm;
	btSymm.read("symmetric.txt");
	btSymm.visualize();	
	cout << "Is this tree symmetric? " << btSymm.is_symmetric() << endl;

	BinaryTree btNotSymm;
	btNotSymm.read("not_symmetric.txt");
	btNotSymm.visualize();
	cout << "Is this tree symmetric? " << btNotSymm.is_symmetric() << endl;

	return 0;
}