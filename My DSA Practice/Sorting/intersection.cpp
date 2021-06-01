#include <iostream>
#include <string>
using namespace std;
void intersection(int arr[], int brr[], int n1, int n2){
    int j=0,i=0;
    while (i<n1 && j<n2){
        if (arr[i]==brr[j]){
            cout << arr[i] << " ";
            while(arr[i]==brr[j])
            j++;
            i++;
        }
        else if (arr[i]>brr[j])
        j++;
        else
        i++;
    }
}
int main(){
    int arr[]={1,1,3,3,3};
    // int arr[]={3,5,10,10,10,15,15,20};
    int brr[]={1,1,1,1,3,5,7};
    // int brr[]={5,10,10,15,30};
    int n1=5, n2=7;
    intersection(arr, brr, n1, n2);
    return 0;
}