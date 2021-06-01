#include <iostream>
using namespace std;

int peak(int arr[], int n){ // naive.
    if (n==1 && arr[0]>=arr[1])
        return 0;
    if (arr[n-1]>=arr[n-2])
        return n-1;
    for (int i=1;i<n-1;i++){
        if (arr[i]>=arr[i-1] && arr[i]>=arr[i+1])
            return i;
    }
    return 234235; // no use.
}
int peak1(int arr[], int n) // optimised.
{
   int low=0, high=n-1;
   while(low<=high){
       int mid=(low+high)/2;
       if (mid==0 && arr[mid+1]<=arr[mid])
       return mid;
       else if (mid==n-1 && arr[mid-1]<=arr[mid])
       return mid;
       else if (arr[mid]>=arr[mid+1] && arr[mid]>=arr[mid-1])
       return mid;
       else if (arr[mid]<=arr[mid-1])
       high=mid-1;
       else 
       low=mid+1;
   }
   return 0; // no use.
}
int peak2(int arr[], int n) // optimised.
{
   int low=0, high=n-1;
   while(low<=high){
       int mid=(low+high)/2;
       if ((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid]))
       return mid;
       if (arr[mid]<=arr[mid-1])
       high=mid-1;
       else
       low=mid+1;
   }
   return 0; // no use.
}
int main(){
    int arr[]={10,20,15};
    int n=3;
    cout << peak(arr, n);

    return 0;
}