#include <iostream>
using namespace std;
int missingNumber(int arr[], int n) { 
        int count=0;
        for (int i=0;i<n;i++){
            if (arr[i]<=0){
                swap(arr[i],arr[count]);
                count++;
            }
        }
        for (int i=count;i<n;i++){
            if(count+abs(arr[i])-1<n && arr[count+abs(arr[i])-1]>0)
            arr[count+abs(arr[i])-1]=-arr[count+abs(arr[i])-1];
        }  
        for (int i=count;i<n;i++){
            if (arr[i]>0){
            return i+1-count;
            }
        }
        return n+1-count;
    } 
int main(){
    int n=1;
    int arr[]={0};
    cout << missingNumber(arr, n);
    return 0;
}