#include <iostream>
using namespace std;

int missingNumber(int arr[], int n) { 
        int j=0;
        for (int i=0;i<n;i++){
            if(arr[i]<=0){
            swap(arr[i],arr[j]);
            j++;}
        }
        for (int i=j;i<n;i++){
            if (abs(arr[i])-1<n && arr[abs(arr[i])-1]>0)
            arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
        }
        for (int i=j;i<n;i++){
            if (arr[i]>0)
        cout << n << " " << j << endl;
            return i-j+1;
        }
        // cout << n << " " << j << endl;
        return n-j+1;
    } 

int main(){
	int arr[]={4,0,2,1,3};
	int n=5;
	return 0;
}