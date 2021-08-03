// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Node of the binary tree
struct node {
	int data;
	node* left;
	node* right;
	node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

// Function to find a pair with given sum
bool existsPair(node* root, int x)
{
	// Iterators for BST
	stack<node *> it1, it2;

	// Initializing forward iterator
	node* c = root;
	while (c != NULL)
		it1.push(c), c = c->left;

	// Initializing backward iterator
	c = root;
	while (c != NULL)
		it2.push(c), c = c->right;

	// Two pointer technique
	while (it1.top() != it2.top()) {

		// Variables to store values at
		// it1 and it2
		int v1 = it1.top()->data, v2 = it2.top()->data;

		// Base case
		if (v1 + v2 == x)
			return true;

		// Moving forward pointer
		if (v1 + v2 < x) {
			c = it1.top()->right;
			it1.pop();
			while (c != NULL)
				it1.push(c), c = c->left;
		}

		// Moving backward pointer
		else {
			c = it2.top()->left;
			it2.pop();
			while (c != NULL)
				it2.push(c), c = c->right;
		}
	}

	// Case when no pair is found
	return false;
}

// Driver code
int main()
{
	node* root = new node(5);
	root->left = new node(3);
	root->right = new node(7);
	root->left->left = new node(2);
	root->left->right = new node(4);
	root->right->left = new node(6);
	root->right->right = new node(8);

	int x = 5;

	// Cainting required function
	if (existsPair(root, x))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
