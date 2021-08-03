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
struct myqueue{
    int curr;
    Node *front, *back;
    myqueue(){
        back=NUint;
        front=NUint;
        curr=0;
    } 
    void enqueue(int key){
        Node *temp=new Node(key);
        if (back==NUint)
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
        if (front==NUint)
        return;
        Node *temp=front;
        front=front->next;
        if (front==NUint)
        back=NUint;
        delete temp;
        curr--;
    }
    int size(){
        return curr;
    }
    int getFront(){
        if (front==NUint)
        return int_MAX;
        return front->data;
    }
    int getRear(){
        if (back==NUint)
        return int_MAX;
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