#include <iostream>
#include <string>
using namespace std;
// memoization based
int count(int arr[], int n, int sum)
{
    if (sum==0)
    return 1;
    if (n==0)
    return 0;
    int res=count(arr, n-1, sum);
    if (arr[n-1]<=sum)
        res+=count(arr, n, sum-arr[n-1]);
    return res;
}
int main(){
    int arr[]={3,2,1};
    int n=sizeof(arr)/sizeof(int);
    cout << count(arr, n, 4);
    return 0;
}
// tabulation based.
/*
#include <iostream>
#define n 3
#define sum 4
using namespace std;
int count(int arr[sum+1][n+1], int s, int no, int arr1[])
{
    if (arr[s][no]==-1)
    {
        if (s==0)
        arr[s][no]=1;
        else if (no==0)
        arr[s][no]=0;
        else{
        int res=count(arr, s, no-1, arr1);
        if (arr1[no-1]<=s)
        res+=count(arr, s-arr1[no-1], no, arr1);
        arr[s][no]=s;
        }
    }
    return arr[s][no];
}
int main(){
    int arr[]={1,2,3};
    int arr1[sum+1][n+1];
    for (int i=0;i<=sum;i++)
    {
        for (int j=0;j<=n;j++)
        {
            arr1[i][j]=-1;
        }
    }
    cout << count(arr1, sum, n, arr) << endl;
    for (int i=0;i<=sum;i++)
    {
        for (int j=0;j<=n;j++)
        {
            // arr1[i][j]=-1;
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/