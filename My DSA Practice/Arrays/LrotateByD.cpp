#include <iostream>
#include <string>
using namespace std;
void Lrotate(int arr[], int n)
{
    int temp = arr[0];
    int i;
    for (i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[i] = temp;
}
void reverse(int arr[], int low, int high){
    while(low<high)
    {
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
}
void LrotateByD(int arr[], int n, int d){ // theta(d*n)
    for (int i=0;i<d;i++){
        Lrotate(arr, n);
    }
}
void LrotateByD1(int arr[], int n, int d){
    int temp[d];
    for (int i=0;i<d;i++)
        temp[i]=arr[i];
    
    for (int i=0;i<n-d;i++)
        arr[i]=arr[i+d];

    for (int i=n-d;i<n;i++)
        arr[i]=temp[i-n+d];
    
    /* or use
    for (int i=0;i<d;i++){
        arr[n-d+i]=temp[i];
    */
}
void LrotateByDMost(int arr[], int n, int d){
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}
int main(){
    int arr[] = {1, 0, 4, 0, 0, 45, 0, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    LrotateByDMost(arr, n, 3);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}