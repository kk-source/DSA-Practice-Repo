#include <iostream>
#include <vector>
using namespace std;
void freq(int arr[], int n){ // different approach by GfG.
    int freq=1;
    int num=arr[0];
    int i;
    for (i=1;i<n;i++){
        if (arr[i]==num)
        freq++;
        else{
        cout << num << " " << freq << endl;
        freq=1;
        num=arr[i];
        }
    }
    cout << num << " " << freq << endl;
}
int main(){
    // int arr[]={5,10,10,10};
    int arr[]={10,10,10,30,30,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    freq(arr, n);
    return 0;
}