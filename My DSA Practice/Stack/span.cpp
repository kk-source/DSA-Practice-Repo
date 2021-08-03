#include <iostream>
#include <stack>
using namespace std;
void span(int arr[], int n){
    cout << 1 << " ";
    for (int i=1;i<n;i++){
        int j=i-1, count=1;
        for (int j=i-1; j>=0 && arr[j]<=arr[i];j--)
        count++;
        cout << count << " ";
    }
}
void span1(int arr[], int n){
    stack<int> s;
    s.push(0); // so that I can compare next element in next iteration.
    // cout << 1 << " ";
    for (int i=0;i<n;i++){
            while(s.empty()==false && arr[s.top()]<=arr[i])
            s.pop();
            int span=(s.empty())? i+1:i-s.top();
            cout << span << " ";
            s.push(i); // so that i can compare next element in next iteration.
    }
}
int main(){
    int arr[]={60,10,20,40,35,30,50,70,65};
    // int arr[]={30,20,25,28,27,29};
    int n=sizeof(arr)/sizeof(int);
    span1(arr, n);

    return 0;
}