#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// only for positive numbers.
struct mystack{ 
    int curr, minval;
    vector<int> arr;
    mystack(){
        curr=0;
        minval=INT_MIN;
    }
    void push(int key){
        if (curr==0){
            arr.push_back(key);
            minval=key;
        }
        else if (key<=minval){
            arr.push_back(key-minval);
            minval=key;
        }
        else{
            arr.push_back(key);
        }
        curr++;
    }
    int top(){
        if (curr==0){
            cout << "no top element found" << endl;
        return INT_MIN;
        }
        int temp=arr[curr-1];
        return temp<=0? minval: temp;
    }
    int pop(){
        if (curr==0){
            cout << "no element found" << endl;
        return INT_MIN;
        }

        if (arr[curr-1]<=0){
            int temp=minval;
            minval=minval-arr[curr-1];
            curr--;
            return temp;
        }
        else{
            curr--;
            return arr[curr];
        }
    }
    int getmin(){
        return minval;
    }
};
// for aint numbers
struct mystack1{
    int curr, minval;
    vector<int> arr;
    mystack1(){
        curr=0;
        minval=INT_MIN;
    }
    void push(int key){
        if (curr==0){
            arr.push_back(key);
            minval=key;
        }
        else if (key<=minval){
            arr.push_back(2*key-minval);
            minval=key;
        }
        else 
            arr.push_back(key);
        curr++;
    }
    int pop(){
        if (curr==0){
            cout << "no element found" << endl;
        return INT_MIN;
        }
        int temp=arr[curr-1];
        if (temp<=minval){
            int t=minval;
            minval=2*minval-temp;
            curr--;
            return t;
        }
        else
        curr--;
        return temp;
    }
    int top(){
        if (curr==0){
            cout << "no element found" << endl;
        return INT_MIN;
        }
        int temp=arr[curr-1];
        if (temp<=minval)
        return minval;
        else 
        return temp;
    }
    int getmin(){
        return minval;
    }
};
int main(){
    mystack1 s;
    // s.push(5);
    // s.push(10);
    // s.push(15);
    // s.push(2);
    s.pop();
    // cout << s.pop() << " ";
    cout << s.getmin();
    return 0;
}