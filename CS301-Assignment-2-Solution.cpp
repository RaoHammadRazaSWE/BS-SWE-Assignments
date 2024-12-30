#include<iostream>
using namespace std;

class BinarySearchTree {
	private:
		int label; 	// label of the node:
		BinarySearchTree* left; // Pointer to the left child
		BinarySearchTree* right;// Pointer  to the right child
		
	public:
		// Default Constructor
		BinarySearchTree() : label(0), left(NULL), right(NULL) {}
		
		// Parameterized Constructor
		BinarySearchTree(int label) : label(label), left(NULL), right(NULL) {}

		// Setter for label
		void setLabel(int label) {
			this->label = label;
		}
		
		// Setter for left child
		void setleft(BinarySearchTree* left) {
			this->left = left;
		}
		
		// Setter for right child
		void setRight(BinarySearchTree* right){
			this->right = right;
		}
		
		// Getter for label
		int getlabel() {
			return label;
		}
		
		// Getter for left child
		BinarySearchTree* getleft() {
			return left;
		}
		
		// Getter for rigth child
		BinarySearchTree* getRight() {
			return right;
		}
		
		// Check if teh node is a leaf node
		int isleaf() {
			return (left == NULL && right == NULL);
		}
		
		// Insert function to add a new node to the tree
		void insert(BinarySearchTree*& root, int label) { // Pass root as reference
			if (label == 0)  // Don't insert 0 in the tree
				return;
				
			if (root == NULL) {
				root = new BinarySearchTree(label); // Insert the node
				cout << label << " inserted successfully." << endl;
				return;
			}
			
			if (label == root->getlabel()) {
				cout << label << " is a duplicate in this Binary Search Tree (BST). Cannot be inserted. " <<endl;
				return; // Don't insert duplicates
			} else if (label < root->getlabel()) {
				insert(root->left, label); // Insert to the left subtree
			}
			else
			{
				insert(root->right, label); // Insert to the right subtree
			}
		}
		
		// In-order traversal to display the tree
		void display(BinarySearchTree* root) {
			if (root != NULL) {
				display(root->left); // Traverse left subtree
				cout<< root->getlabel() << " " ; // Rrint node label
				display(root->right); // Traverse right subtree
			}
		}	
};

int main(){
	int numId = 1291;
	cout << "Your Student ID First two and last two digits are : " << numId << endl;
	
	BinarySearchTree* bst = NULL;
	
	while (numId > 0 ) {
		int digit = numId % 10;
		bst->insert(bst, digit);
		numId /= 10;
	}
	
	cout<< "Displaying the Tree Nodes in in-order sequence: ";
	bst->display(bst);
	cout<< endl;
	
	return 0;
}
