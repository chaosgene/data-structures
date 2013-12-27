#include <iostream>
#include "BinaryTree.h"
#include <string>
#include <climits>
#include <complex>
#include <fstream>

using namespace std;

// Constructor
BinaryTree::BinaryTree()
: root(nullptr)
{
}

/***** BIG THREE *****/

// Helper recursive function
void BinaryTree::destructor_helper(BinaryTree::BinNode * binTree)
{
	if (binTree != nullptr)
	{
		destructor_helper(binTree->left);
		destructor_helper(binTree->right);
		delete binTree;
	}
}

// Destructor
BinaryTree::~BinaryTree()
{
	destructor_helper(root);
}

// Copy constructor
BinaryTree::BinaryTree(const BinaryTree & other)
{
	root = copyAux(other.root);
}

BinaryTree::BinNode * BinaryTree::copyAux(const BinNode * other)
{
	if (other == nullptr)
		return nullptr;
	BinNode * newBinNode = new BinNode(other->datum);
	newBinNode->left = copyAux(other->left);
	newBinNode->right = copyAux(other->right);
	return newBinNode;
}

// Assignment operator
BinaryTree& BinaryTree::operator=(const BinaryTree &rhs)
{
	if (this != &rhs) // self-copy guard
	{
		if (root != nullptr)
			destructor_helper(root);
		if (rhs.root == nullptr)
			root = nullptr;
		else
			root = copyAux(rhs.root);
	}
	return *this;
}

// Get if empty
bool BinaryTree::empty()
{
	return (root == nullptr);
}

// Helper recursive function
bool BinaryTree::search_helper(int data, BinNode * binTree)
{
	if (binTree == nullptr)
		return false;
	else if (binTree->datum == data)
		return true;
	return (search_helper(data, binTree->left) || search_helper(data, binTree->right));
}

// Get if tree contains data
bool BinaryTree::search(int data)
{
	return (search_helper(data, root));
}

BinaryTree::BinNode* BinaryTree::find_helper(int data, BinNode * root)
{
	if (root == nullptr)
		return nullptr;
	else if (root->datum == data)
		return root;	
	BinNode* answer = find_helper(data, root->left);

	if (answer == nullptr)
		return	find_helper(data, root->right);
	else
		return answer;
}

// Get address of node storing data
BinaryTree::BinNode* BinaryTree::find(int data)
{
	return find_helper(data, root);
}

bool BinaryTree::is_BST_helper(BinNode * binTree, int min, int max)
{
	if (binTree == nullptr)
		return true;
	if (binTree->datum < min || binTree->datum > max)
		return false;
	return is_BST_helper(binTree->left, min, binTree->datum) &&
		is_BST_helper(binTree->right, binTree->datum+1, max);
}

// Get if it follows the BST rule
bool BinaryTree::is_BST()
{
	return is_BST_helper(root, INT_MIN, INT_MAX);
}

// Helper recursive function
int BinaryTree::height_helper(BinNode * binTree)
{
	if (binTree == nullptr)
		return 0;
	int left = height_helper(binTree->left);
	int right = height_helper(binTree->right);
	return 1 + std::max(left, right);
}

// Binary tree height
int BinaryTree::height()
{
	int ans = 0;
	ans = height_helper(root);

	if (ans > 0)
		return (ans - 1);
	return ans;
}

// Helper recursive function
bool BinaryTree::is_balanced_helper(BinNode * root)
{
	int left;
	int right;
	if (root == nullptr)
		return true;
	left = height_helper(root->left);
	right = height_helper(root->right);
	if(abs(left-right) <= 1 &&
		is_balanced_helper(root->left) &&
		is_balanced_helper(root->right))
		return true;
	return false;
}

// Check if for any node, the height of the subtrees differ at most by 1
bool BinaryTree::is_balanced()
{
	return is_balanced_helper(root);
}

/**** MUTATORS *****/

// Helper recursive function
void BinaryTree::insert_helper(int data, BinNode * &binTree)
{
	// current implementation maintains BST property
	if (binTree == nullptr)
	{
		binTree = new BinNode(data);
	}	
	else if (binTree->datum > data)
	{
		insert_helper(data, binTree->left);
	}
	else if (binTree->datum <= data)
	{
		insert_helper(data, binTree->right);
	}
}

// Stick some data into the binary tree
void BinaryTree::BSTinsert(int data)
{
	insert_helper(data, root);
}

// Fast insert method 
void BinaryTree::insert(int data)
{
	BinNode * temp = root;
	root = new BinNode(data);
	root->left = temp;
}

// Helper function made to amputate a node from the tree
void BinaryTree::killNode(BinNode * &binTree)
{
	BinNode * temp;
	temp = binTree;
	if (binTree->left == nullptr) // no left child
	{
		binTree = binTree->right;
		delete temp;
	}
	else if (binTree->right == nullptr) // no right child
	{
		binTree = binTree->left;
		delete temp;
	}
	else // both left and right child exist
	{
		temp = binTree->left;
		while (temp->right != nullptr)
			temp = temp->right;
		binTree->datum = temp->datum;
		remove_helper(binTree->left, temp->datum);
	}
}

// Helper recursive function
void BinaryTree::remove_helper(BinNode * &binTree, int data)
{
	if (binTree != nullptr)
	{
		if (binTree->datum == data)
		{
			killNode(binTree);	
			return;
		}
		remove_helper(binTree->left, data);
		remove_helper(binTree->right, data);
	}
}

// Removes a node with the given data
void BinaryTree::remove(int data)
{
	remove_helper(root, data);
}

/***** TRAVERSALS *****/

#include <iomanip>
// Helper recursive function
void BinaryTree::pre_order_helper(BinNode * root) const
{
	if (root != nullptr)
	{
		int leftVal = -1;
		if (root->left != nullptr)
			leftVal = (root->left)->datum;
		int rightVal = -1;
		if (root->right != nullptr)
			rightVal = (root->right)->datum;
		cout << setw(15) << left << " " <<  setw(15) << left << root->datum << setw(15) << left << leftVal << setw(15) << left <<  rightVal << endl;
		cout << setw(15) << left << "Address: " << setw(15) << left <<  root << setw(15) << left << root->left << setw(15) <<  left << root->right << endl << endl;
		pre_order_helper(root->left);
		pre_order_helper(root->right);
	}
}

// Pre-order traversal display
void BinaryTree::pre_order() const
{
	cout << "PRE-ORDER: ~~~~~~~~~~ " << endl;
	cout << setw(15) << left << " " << setw(15) << left << "Node" << setw(15) << left << "Left Child" << setw(15) << left << "Right Child" << endl << endl;
	pre_order_helper(root);
	cout << endl;
}

// Helper recursive function
void BinaryTree::in_order_helper(BinNode * root) const
{
	if (root != nullptr)
	{
		in_order_helper(root->left);
		int leftVal = -1;
		if (root->left != nullptr)
			leftVal = (root->left)->datum;
		int rightVal = -1;
		if (root->right != nullptr)
			rightVal = (root->right)->datum;
		cout << setw(15) << left << " " <<  setw(15) << left << root->datum << setw(15) << left << leftVal << setw(15) << left <<  rightVal << endl;
		cout << setw(15) << left << "Address: " << setw(15) << left <<  root << setw(15) << left << root->left << setw(15) <<  left << root->right << endl << endl;
		in_order_helper(root->right);
	}
}

// In-order traversal display
void BinaryTree::in_order() const
{
	cout << "IN_ORDER: ~~~~~~~~~~ " << endl;
	cout << setw(15) << left << " " << setw(15) << left << "Node" << setw(15) << left << "Left Child" << setw(15) << left << "Right Child" << endl << endl;
	in_order_helper(root);
	cout << endl;
}

// Helper recursive function
void BinaryTree::post_order_helper(BinNode * root) const
{
	if (root != nullptr)
	{
		post_order_helper(root->left);
		post_order_helper(root->right);
		int leftVal = -1;
		if (root->left != nullptr)
			leftVal = (root->left)->datum;
		int rightVal = -1;
		if (root->right != nullptr)
			rightVal = (root->right)->datum;
		cout << setw(15) << left << " " <<  setw(15) << left << root->datum << setw(15) << left << leftVal << setw(15) << left <<  rightVal << endl;
		cout << setw(15) << left << "Address: " << setw(15) << left <<  root << setw(15) << left << root->left << setw(15) <<  left << root->right << endl << endl;
	}
}

// Post-order traversal display
void BinaryTree::post_order() const
{
	cout << "POST_ORDER: ~~~~~~~~~~ " << endl;
	cout << setw(15) << left << " " << setw(15) << left << "Node" << setw(15) << left << "Left Child" << setw(15) << left << "Right Child" << endl << endl;
	post_order_helper(root);
	cout << endl;
}

// Helper recursive function
void BinaryTree::write_helper(BinNode * root, ostream &outfile)
{
	if (root != nullptr)
	{
		outfile << root->datum << " ";
		write_helper(root->left, outfile);
		write_helper(root->right, outfile);
	}
	else // use -1 to denote a null subtree
	{
		outfile << "-1" << " ";
	}
}

// FILE OUTPUT
void BinaryTree::write(string file_name)
{
	ofstream outfile;
	outfile.open(file_name);
	if (!outfile.is_open())
	{
		cerr << "Unable to open file.";
		return;
	}
	cout << "Writing to: " << file_name << endl;
	write_helper(root, outfile);
	outfile.close();
}

// Helper recursive function
void BinaryTree::read_helper(BinNode * &root, istream &infile)
{
	int number;
	while (infile >> number)
	{
		if (number < 0)
		{
			return;
		}
		else if (number >=  0)
		{
			root = new BinNode(number);
			read_helper(root->left, infile);
			read_helper(root->right, infile);
			return;
		}
	}
};

// FILE INPUT
void BinaryTree::read(string file_name)
{
	ifstream infile;
	infile.open(file_name);
	if (!infile.is_open())
	{
		cerr << "Unable to open file.";
		return;	
	}
	cout << "Reading from: " << file_name << endl;
	read_helper(root, infile);
	infile.close();
}

// Graphical version of a Binary Tree
#include <iomanip>
void BinaryTree::visualize_helper(int indent, BinNode * binTree) const
{
	if (binTree != nullptr)
	{
		visualize_helper(indent + 8, binTree->right);
		cout << setw(indent) << " " << binTree->datum << endl;
		visualize_helper(indent + 8, binTree->left);
	}	
}

void BinaryTree::visualize() const
{
	visualize_helper(0, root);
}

bool BinaryTree::is_symmetric()
{
	return is_symmetric_aux(root->left, root->right);
}

bool BinaryTree::is_symmetric_aux(BinNode * lChild, BinNode * rChild)
{
	if ((rChild == nullptr) || (lChild == nullptr))	
		return ((lChild == nullptr)&&(rChild == nullptr));
	return ((lChild->datum == rChild->datum) &&
		 (is_symmetric_aux((lChild->left), (rChild->right))) &&
		 (is_symmetric_aux((lChild->right), (rChild->left))));
}
