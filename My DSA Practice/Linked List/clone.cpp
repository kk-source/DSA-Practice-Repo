#include <bits/stdc++.h> 
using namespace std; 

struct node 
{ 
    int data; 
    node *next,*random; 
    node(int x) 
    { 
        data = x; 
        next = random = NULL; 
    } 
}; 

void print(node *start) 
{ 
    node *ptr = start; 
    while (ptr) 
    { 
        cout << "Data = " << ptr->data << ", Random  = ";
        cout<< ptr->random->data;
        cout<< endl;  // ye bolrha hu if(ptr->random)
        ptr = ptr->next; 
    } 
}

node* clone(node *head) 
{ 
    unordered_map<node*,node*> hm;
    for(node *curr=head;curr!=NULL;curr=curr->next)
        hm[curr]=new node(curr->data);
    
    for(node *curr=head;curr!=NULL;curr=curr->next){
        node *cloneCurr=hm[curr];
        cloneCurr->next=hm[curr->next];
        cloneCurr->random=hm[curr->random];
    }
    node *head2=hm[head];
    
    return head2;
}

node* clone1(node *head){
    // inserting clone elements in between.
    for (node *curr=head; curr!=NULL;){
        node *next=curr->next;
        curr->next=new node(curr->data);
        curr->next->next=next;
        curr=next;
    }
    // defining random pointers.
    for (node *curr=head; curr!=NULL;curr=curr->next->next)
        curr->next->random=(curr->random!=NULL)? curr->random->next:NULL;
    
    node *head2=head->next;
    node *head1=head;
    for (node *curr=head; curr->next!=NULL;){
        
        node *next=curr->next;
        curr->next=next->next;
        curr=next;
    }
    return head2;
    // while (original && copy) 
    // { 
    //     original->next = 
    //      original->next? original->next->next : original->next; 
  
    //     copy->next = copy->next?copy->next->next:copy->next; 
    //     original = original->next; 
    //     copy = copy->next; 
    // } 
  
    // return temp; 
}
int main() 
{ 
	node* head = new node(10); 
    head->next = new node(5); 
    head->next->next = new node(20); 
    head->next->next->next = new node(15); 
    head->next->next->next->next = new node(20); 
    
    head->random = head->next->next;
    head->next->random=head->next->next->next;
    head->next->next->random=head;
    head->next->next->next->random=head->next->next;
    head->next->next->next->next->random=head->next->next->next;
    
    cout << "Original list : \n"; 
    print(head); 
  
    cout << "\nCloned list : \n"; 
    node *cloned_list = clone1(head); 
    print(cloned_list); 
  
    return 0; 
} 
