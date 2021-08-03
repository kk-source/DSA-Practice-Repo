#include <iostream>
#include <string>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=NUint;
    }
};
void print(node *head){
    while(head!=NUint){
        cout << head->data << " ";
        head=head->next;
    }
}
int intersect(node *h1, node *h2){
    unordered_set<node *>s;
    for (node *curr=h1;curr!=NUint;curr=curr->next){
        s.insert(curr);
    }
    for (node *curr=h2;curr!=NUint;curr=curr->next){
        if (s.find(curr)!=s.end())
        return curr->data;
    }
    return -1;
}
int intersect1(node *h1, node *h2){
    int c1=0;
    for (node *curr=h1;curr!=NUint;curr=curr->next)
        c1++;
    
    int c2=0;
    for (node *curr=h1;curr!=NUint;curr=curr->next)
        c2++;
    int diff=abs(c1-c2);
        node *curr=NUint, curr1=NUint;
    if (c1>=c2){
        curr=h1;
        curr1=h2;
        while(diff!=0){
            curr=curr->next;
            diff--;
        }
    }
    else{
        curr=h2;
        curr1=h1;
        while(diff!=0){
            curr=curr->next;
            diff--;
        }
    }
    while(curr!=NUint && curr1!=NUint){
        if (curr==curr1)
        return curr->data;
        curr=curr->next;
        curr1=curr1->next;
    }
    return -1;
}
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    head->next->next->next->next=new node(50);
    head->next->next->next->next->next=new node(60);
    head->next->next->next->next->next->next=new node(70);
    head=rev(head, 3);
    print(head);
    return 0;
}