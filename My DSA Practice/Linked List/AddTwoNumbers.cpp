#include <iostream>
#include <string>
using namespace std;
Node* addSameSize(Node* head1, Node* head2, int* carry) 
{ 
	if (head1 == NULL) 
		return NULL; 

	int sum = 0;
	
	//allocating memory for sum node of current two nodes.
    Node* result = new Node(sum);
	
	//recursively adding remaining nodes and getting the carry.
	result->next = addSameSize(head1->next, head2->next, carry); 
    
    //adding digits of current nodes and propagating carry.
	sum = head1->data + head2->data + *carry; 
	*carry = sum / 10; 
	sum = sum % 10; 

    //assigning the sum to current node of resultant list.
	result->data = sum;

	return result; 
} 

//Function to add remaining carry.
void addCarryToRemaining(Node* head1, Node* curr, int* carry, Node** result) 
{ 
	int sum; 
    
	if (head1 != curr) 
	{ 
	    //calling function recursively to add carry.
		addCarryToRemaining(head1->next, curr, carry, result); 

		sum = head1->data + *carry; 
		*carry = sum/10; 
		sum %= 10;

		//adding this node to the front of the resultant list. 
		push(result, sum); 
	} 
	return;
}
int main(){
    

    return 0;
}