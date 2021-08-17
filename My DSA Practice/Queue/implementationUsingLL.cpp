#include <iostream>
#include <string>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
struct myqueue{
    int curr;
    Node *front, *back;
    myqueue(){
        back=NULL;
        front=NULL;
        curr=0;
    } 
    void enqueue(int key){
        Node *temp=new Node(key);
        if (back==NULL)
        {
            back=temp;
            front=back;
        }
        else{
            back->next=temp;
            back=temp;
        }
        curr++;
    }
    void dequeue(){
        if (front==NULL)
        return;
        Node *temp=front;
        front=front->next;
        if (front==NULL)
        back=NULL;
        delete temp;
        curr--;
    }
    int size(){
        return curr;
    }
    int getFront(){
        if (front==NULL)
        return INT_MAX;
        return front->data;
    }
    int getRear(){
        if (back==NULL)
        return INT_MAX;
        return back->data;
    }
    bool isempty(){
        return curr==0;
    }
};
int main(){
    myqueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    // q.dequeue();
    cout << q.size()<< " ";
    cout << q.getRear()<< " ";
    cout << q.getFront()<< " ";
    cout << q.isempty()<< " ";
    return 0;
}