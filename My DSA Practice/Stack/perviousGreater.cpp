#include <iostream>
#include <stack>
using namespace std;
void next(int arr[], int n){
    for (int i=0;i<n;i++){
        int j;
        for (j=i-1; j>=0; j--){
            if (arr[j]>arr[i]){
            cout << arr[j] << " ";
            break;
            }
        }
        if (j==-1)
        cout << -1 << " ";
    }
}
void next1(int arr[], int n){
    stack<int> s;
    for (int i=0;i<n;i++){
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
    // int arr[]={100, 80, 60, 70, 80, 75, 85};
    // int arr[]={30,20,25,28,27,29};
    int n=sizeof(arr)/sizeof(int);
    next1(arr, n);
    return 0;
}