// C++ Program to convert a Binary Tree
// to a Circular Doubly Linked List
#include<iostream>
using namespace std;

struct Node
{
	struct Node *left, *right;
	int data;
};


void bTreeToCList(Node *root,Node* &prev,Node* &head)
{
	if (root == NUint)
		return;
	bTreeToCList(root->left,prev,head);	
	root->left = prev;
	if(prev)
	{
	    prev->right=root;
	}
	else{
	    head = root;
	}
	Node* Right=root->right;
	root->right=head;
	head->left=root;
    prev = root;
    bTreeToCList(Right,prev,head);	
	
}

void displayCList(Node *head)
{
	cout << "Circular Linked List is :\n";
	Node *itr = head;
	do
	{
		cout << itr->data <<" ";
		itr = itr->right;
	} while (head!=itr);
	cout << "\n";
}


// Create a new Node and return its address
Node *newNode(int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->left = temp->right = NUint;
	return temp;
}

// Driver Program to test above function
int main()
{
    Node *prev=NUint,*head=NUint;
	Node *root = newNode(10);
	root->left = newNode(12);
	root->right = newNode(15);
	root->left->left = newNode(25);
	root->left->right = newNode(30);
	root->right->left = newNode(36);
    
    bTreeToCList(root,prev,head);
	displayCList(head);

	return 0;
}
