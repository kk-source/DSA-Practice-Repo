#include <iostream>
#include <string>
using namespace std;
struct mqueue1{
    int size, curr;
    int *arr;
    myqueue(int x){
        size=x;
        curr=-1;
        arr=new int [x];
    }
    int getsize(){
    return curr+1;
    }
    int getfront(){
        return (curr==-1)? INT_MIN:arr[curr];
    }
    int getrear(){
        return (curr==-1)? INT_MIN:arr[0];
    }
    bool isFull(){
        return (curr==size-1);
    }
    bool isEmpty(){
        return (curr==-1);
    }
    void enqueue(int key){
        if (isFull())
        return;
        curr++;
        arr[curr]=key;
    }
    void dequeue(){
        // O(n) operation.
        if(curr==-1)
        return;
        for (int i=0;i<curr;i++)
        arr[i]=arr[i+1];
        curr--;
    }
};
//rear=front+size-1;
struct mqueue
{
int curr, size, front, *arr, rear;
mqueue(int x)
{
size=x;
curr=0;
rear=x-1;
arr= new int[x];
front=0;
}

bool isfull(){
return curr==size;
}

bool isempty(){
return curr==0;
}

void enqueue(int key){
if (isfull()){
cout << "full" << endl;
return;
}
rear=(rear+1)%size;
arr[rear]=key;
curr++;
}

void dequeue(){
if (isempty())
{
cout << "empty" << endl;
return ;
}
front=(front+1)%size;
curr--;
}

int getsize(){
return curr;}

int getRear(){
if (isempty())
return INT_MAX;
return arr[rear];
}

int getFront(){
if (isempty())
return INT_MAX;
return arr[front];
}

};
int main()
{
    mqueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(30);
    q.enqueue(30);
    q.enqueue(30);
    q.dequeue();
    cout << q.getsize() << " ";
    cout << q.getFront() << " ";
    cout << q.getRear() << " ";
    cout << q.isfull() << " ";
    cout << q.isempty() << " ";
    return 0;
}