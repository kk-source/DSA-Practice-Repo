#include <iostream>
#include <string>
using namespace std;
int removeDup(int arr[], int n)
{
    int temp[n];
    int res = 1;
    temp[0]=arr[0];
    for (int i=1;i<n;i++){
        if (temp[res-1]!=arr[i]){
            temp[res]=arr[i];
            res++;
        }
    }
    for (int i=0;i<res;i++){
        arr[i]=temp[i];
    }
    return res;
}
int removeDupMost(int arr[], int n)
{   
    int res=1;
    for (int i=1;i<n;i++){
        if (arr[i]!=arr[res-1]){
            arr[res]=arr[i];
            res++;
        }
    }
    return res;
}
int main()
{
    int arr[] = {1,2,2,2,3,4,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << removeDupMost(arr, n) << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    int arr1[] = {1,2,2,2,3,4,6};
    cout << removeDup(arr1, n) << endl;
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    return 0;
}