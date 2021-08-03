#include <iostream>
#include <stack>
using namespace std;
void next(int arr[], int n){
    for (int i=0;i<n;i++){
        int j;
        for (j=i+1; j<n; j++){
            if (arr[j]>arr[i]){
            cout << arr[j] << " ";
            break;
            }
        }
        if (j==n)
        cout << -1 << " ";
    }
}
void next1(int arr[], int n){ // prints in reverse order.
    stack<int> s;
    for (int i=n-1;i>=0;i--){
        while(s.empty()==false && s.top()<=arr[i]){
            s.pop();
        }
        int span = (s.empty())? -1:s.top();
        cout << span << " ";
        s.push(arr[i]);
    }
}
int main(){
    int arr[]={60,10,20,40,35,30,50,70,65};
    // int arr[]={30,20,25,28,27,29};
    int n=sizeof(arr)/sizeof(int);
    next1(arr, n);
    cout << endl;
    next(arr, n);
    return 0;
}