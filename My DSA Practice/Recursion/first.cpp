#include <iostream>
using namespace std;

int fun(int n){ // gives floor log2 n.
    if (n==1)
    return 0; 
    return 1+fun(n/2);
}
void fun1(int n){ // prints binary representation of number.
    if (n==0)
    return;
    fun1(n/2);
    cout << n%2;
}
void fun2(int n){ // prints in decreasing order.
    if (n==0)
    return;
    cout << n << endl;
    fun2(n-1);
}
void fun3(int n){ // prints in increasing order.
    if (n==0)
    return;
    fun3(n-1);
    cout << n << " ";
}
int sum(int n){
    if (n==0)
    return 0;
    return n+sum(n-1);
}
bool palin(string &str){
    int n=str.size();
    if (n==0 || n==1)
    return true;
    if (str[0]!=str[n-1])
    return false;
    string temp=str.substr(1,n-2);
    return palin(temp);
}
int sumOfDigits(int n){
    if (n==0) // if(n<=9)
    return 0; // return n;
    return n%10+sumOfDigits(n/10);
}
int main(){
    // cout << sumOfDigits(467);
    // string str="ba";
    // // cout << palin(str);
    cout << fun(8);
    return 0;
}
