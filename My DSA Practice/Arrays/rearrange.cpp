#include<iostream>
using namespace std;

void arrange(int arr[], int n) {
        for (int i=0;i<n;i++){
            arr[i]=arr[arr[i]]%n*n+arr[i];
        }
        for (int i=0;i<n;i++){
            arr[i]/=n;
            cout << arr[i] << " ";
        }
    }
int main(){
	int arr[]={4,0,2,1,3};
	int n=5;
    arrange(arr,n);
	return 0;
}