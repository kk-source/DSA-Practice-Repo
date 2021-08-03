#include <iostream>
#include <string>
using namespace std;

struct Node{
    int key, value;
    Node *prev, *next;
    Node(int x, int y){
        key=x;
        value=y;
        prev=next=NULL;
    }
};
class LRUCache
{
    private:
    int size;
    int curr;
    Node *head, *tail;
    unordered_map<int, Node*> mp;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        size=cap;
        curr=0;
        head=new Node(0, 0);
        tail=new Node(0, 0);
        head->next=tail;
        tail->prev=head;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if (mp.find(key)==mp.end())
        return -1;
        Node *temp=mp[key];
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        temp->next=head->next;
        temp->prev=head;
        head->next=temp;
        return temp->value;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if (mp.find(key)!=mp.end())
        return;
        Node *temp;
        if (curr==size){
            temp=tail->prev;
            mp.erase(temp->key);
            temp->prev->next=tail;
            tail->prev=temp->prev;
            delete temp;
        }
        temp=new Node(key, value);
        mp[key]=temp;
        temp->next=head->next;
        temp->next->prev=temp;
        head->next=temp;
        temp->prev=head;
        curr+=(curr==size)? 0:1;
    }
};
int main(){
    

    return 0;
}