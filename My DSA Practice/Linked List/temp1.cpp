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

int main(){
    int size;
    int curr;
    Node *head, *next;
    unordered_map<int, int> m;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        size=cap;
        curr=0;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if (m.find(key)!=m.end())
        return m[key];
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if (m.find(key)!=m.end()){
            Node *z=head;
            while(z->data!=key)
            z=z->next;
            if (z==next){
                next=z->prev;
                delete z;
                next->next=NULL;
            }
            else{
            if (z->prev)
            z->prev->next=z->next;
            if (z->next)
            z->next->prev=z->prev;
            delete z;
            }
            z=new Node(key);
            z->next=head;
            head->prev=z;
            head=z;
        }
        else {
        if (curr==0){
            m.insert({key, value});
            head=new Node(key);
            next=head;
            curr++;
        }
        else if(curr<size){
            m.insert({key, value});
            Node *temp=new Node(key);
            temp->next=head;
            head->prev=temp;
            head=temp;
            curr++;
        }
        else if (curr==size){
            m.erase(next->data);
            Node *temp=next;
            next=next->prev;
            delete temp;
            next->next=NULL;
            m.insert({key, value});
            temp=new Node(key);
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        }
    }

    return 0;
}