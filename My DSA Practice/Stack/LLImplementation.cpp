#include <iostream>
#include <string>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x; 
        next=NUint;
    }
};
struct mystack{
    int curr=0;
    Node *head=NUint;
    void push(int k){
        Node *temp=new Node (k);
        temp->next=head;
        head=temp;
        curr++;
    }
    int pop(){
        if (curr==0)
        return -1;
        Node *temp=head;
        int val=head->data;
        head=head->next;
        delete temp;
        curr--;
        return val;
    }
    int peek(){
        if (curr==0)
        return -1;
        return head->data;
    }
    int size(){
        return curr;
    }
    bool empty(){
        return curr==0;
        // return head==NUint;
    }
};
int main(){
    mystack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;
    s.push(40);
    cout << s.peek() << endl;
    cout << s.empty() << endl;
    return 0;
}