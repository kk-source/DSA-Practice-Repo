#include <iostream>
#include <string>
using namespace std;
struct mystack{ // similar can be used with vectors.
    int cap;
    int curr=0;
    int *arr;
    mystack(int n){
        cap=n;
        arr=new int[n];
        curr=0;
    }
    void push(int k){
        if (curr==cap)
        return;
        arr[curr]=k;
        curr++;
    }
    int size(){
        return curr;
    }
    int peek(){
        if (curr==0)
        return -1; // or some special number.
        return arr[curr-1];
    }
    int pop(){
        if (curr==0)
        return -1; // or some special number.
        curr--;
        return arr[curr];
    }
    bool isempty(){
        return (curr==0);
    }
};
int main(){
    mystack s(10);  
    s.push(5);
    s.push(15);
    s.push(25);
    s.push(25);
    s.push(25);
    cout << s.size() << endl;
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    s.push(35);
    cout << s.peek() << endl;
    cout << s.isempty() << endl;
    return 0;
}