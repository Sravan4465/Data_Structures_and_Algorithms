// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Class describing a node of tree
class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int v)
	{
		this->data = v;
		this->left = this->right = NULL;
	}
};

// Preorder Traversal
void printPreOrder(Node* node)
{
	if (node == NULL)
		return;

	// Visit Node
	cout << node->data << " ";

	// Traverse left subtree
	printPreOrder(node->left);

	// Traverse right subtree
	printPreOrder(node->right);
}

void printPostOrder(Node* node)
{
	if (node == NULL)
		return;

	// Traverse left subtree
	printPostOrder(node->left);

	// Traverse right subtree
	printPostOrder(node->right);

    // Visit Node
	cout << node->data << " ";
}

void printInOrder(Node* node)
{
	if (node == NULL)
		return;

	// Traverse left subtree
	printInOrder(node->left);

    // Visit Node
	cout << node->data << " ";

	// Traverse right subtree
	printInOrder(node->right);
}

// Driver code
int main()
{
	// Build the tree
	Node* root = new Node(100);
	root->left = new Node(20);
	root->right = new Node(200);
	root->left->left = new Node(10);
	root->left->right = new Node(30);
	root->right->left = new Node(150);
	root->right->right = new Node(300);

	// Function call
	cout << "Preorder Traversal: ";
	printPreOrder(root);
    cout<<endl;
    cout << "Postorder Traversal: ";
	printPostOrder(root);
    cout<<endl;
    cout << "Inorder Traversal: ";
	printInOrder(root);
	return 0;
}
