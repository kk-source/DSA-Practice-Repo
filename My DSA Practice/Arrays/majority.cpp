#include <iostream>
#include <vector>
using namespace std;
int majority(int arr[], int n){
    for(int i=0;i<n-1;i++){
    int count=1;
        for (int j=i+1;j<n;j++){
        if (arr[i]==arr[j])
        count++;   
        if (count>n/2)
        return i;
        }
        
    }
    return -1;
}
int majorityMost(int arr[], int n){
    int res=0, count=1;
    for (int i=1;i<n;i++){
        if (arr[res]==arr[i])
        count++;
        else
            count--;
        if (count==0)
        {res=i;count=1;}
    }
    count=0;//using this variable to see if the element is majority.
    for (int i=0;i<n;i++){
        if (arr[i]==arr[res])
        count++;
        if (count>n/2){
        return res;
        }
    }
    return -1;
}
int main(){
    int arr[]={8,3,4,8,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << majorityMost(arr,n);

    return 0;
}