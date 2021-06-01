#include <iostream>
#include <string>
using namespace std;
void leader(int arr[], int n){ // O(n^2);
    for (int i=0;i<n;i++){
        int j=i+1;
        for (;j<n;j++){
            if (arr[j]>=arr[i])
            break;
        }
        if (j==n) // or use flag concept.
        cout << arr[i] << " ";
    }
}
void leaderMost(int arr[], int n){ // theta(n);
    int lead=arr[n-1];
    cout << lead << " ";
    for (int i=n-2;i>=0;i--){
        if (arr[i]>lead){
            lead=arr[i];
            cout << lead << " ";
        }
    }
    // can print from l to r also by storing leaders in an array and printing them later after reversing that array-theta(n).
}
int main(){
    int arr[]={7,10,4,10,6,5,2};
    // int arr[]={30,20,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    leader(arr, n);
    return 0;
}