#include <iostream>
#include <string>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=NULL;
    }
};
void print(node *head){
    while(head!=NULL){
        cout << head->data << " ";
        head=head->next;
    }
}
void noFromEnd(node *head, int k){
    int count=1, ans=-1;
    node *curr=head;
    while(curr!=NULL){
        if (count>=n){
            ans=head->data;
            head=head->next;
        }
        curr=curr->next;
        count++;
    }
    cout << ans->data;
}
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    // head->next->next->next=new node(40);
    // head->next->next->next->next=new node(50);
    noFromEnd(head, 0);
    return 0;
}