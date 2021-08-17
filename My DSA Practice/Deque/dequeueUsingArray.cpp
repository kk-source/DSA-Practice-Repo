#include<iostream>
using namespace std;
// other implementation can be simple where
// front is always at zero.
// fdelete and finsert will be O(n).
struct mdequeue{
int front, curr, size, *arr;
mdequeue(int x){
size=x;
curr=0;
front=0;
arr=new int[x];
}
// rear=(front+curr-1)%size.
bool isfull(){
return curr==size;
}

bool isempty(){
return curr==0;
}
void finsert(int key){
if (isfull()){
cout << "full" << endl;
return;}
front=(front-1+size)%size;
arr[front]=key;
curr++;
}

void rinsert(int key){
if (isfull()){
cout << "full" << endl;
return;
}
int newrear=(front+curr)%size;
arr[newrear]=key;
curr++;
}

void fdelete(){
if (isempty()){
cout << "empty" << endl;
return;
}
front=(front+1)%size;
curr--;
}

void rdelete(){
if (isempty()){
cout << "empty" << endl;
return;
}
int rear=(front+curr-1)%size;
curr--;
}

int getfront(){
if (isempty())
return INT_MAX;
return arr[front];
}

int getrear(){
if (isempty())
return INT_MAX;
int rear=(front+curr-1)%size;
return arr[rear];
}

int getsize(){
return curr;
}
};
int main()
{
    mdequeue dq(5);
    //dq.finsert(10);
    dq.rinsert(20);
    dq.finsert(120);
    //dq.rinsert(40);
    //dq.rinsert(100);
    //dq.rinsert(50);
    //dq.fdelete();
    //dq.rdelete();
    cout << dq.getfront() << " ";
    cout << dq.getrear() << " ";
    cout << dq.getsize() << " ";
    cout << dq.isempty() << " ";
    cout << dq.isfull() << " ";
    return 0;
}