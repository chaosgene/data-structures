#ifndef BINARYTREE
#define BINARYTREE
#include <string>
#include <fstream>
class BinaryTree
{
	private:
		class BinNode
		{
			public:
				int datum;
				BinNode * left;
				BinNode * right;
			
				BinNode()
				: left(nullptr), right(nullptr)
				{}

				BinNode(int specVal)
				: datum(specVal), left(nullptr), right(nullptr)
				{}
		};

		/*** Private Member Functions ***/
		void destructor_helper(BinNode * binTree);
		bool search_helper(int data, BinNode * binTree);
		BinNode* find_helper(int data, BinNode * root);
		bool is_BST_helper(BinNode * binTree, int min, int max);
		int height_helper(BinNode * binTree);
		bool is_balanced_helper(BinNode * root);
		void insert_helper(int data, BinNode * &binTree);
		void killNode(BinNode * &binTree);
		void remove_helper(BinNode * &binTree, int data);
		void pre_order_helper(BinNode * root) const;
		void in_order_helper(BinNode * root) const;
		void post_order_helper(BinNode * root) const;	
		void write_helper(BinNode * root, std::ostream &outfile);
		void read_helper(BinNode * &root, std::istream &infile);
		void visualize_helper(int indent, BinNode * binTree) const;
		bool is_symmetric_aux(BinNode * lChild, BinNode * rChild);	
	public:
		BinaryTree(); // Constructor
		~BinaryTree(); // Destructor
		BinaryTree(const BinaryTree & other); // Copy constructor
		BinNode* copyAux(const BinNode * other);
		BinaryTree& operator=(const BinaryTree &rhs); // Assignment operator
		bool empty();
		bool is_symmetric();
		bool search(int data);
		BinNode* find(int data);
		bool is_BST();
		int height();
		bool is_balanced();
		void BSTinsert(int data);
		void insert(int data);
		void remove(int data);
		void pre_order() const;
		void in_order() const;
		void post_order() const;
		void write(std::string file_name);
		void read(std::string file_name);
		void visualize() const;
		
		BinNode *root;
};

#endif