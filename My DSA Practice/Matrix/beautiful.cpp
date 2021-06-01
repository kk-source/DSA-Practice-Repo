#include <iostream>
#include <string>
using namespace std;
int findMinOpeartion(int n, int arr[][3])
{
    int maxval=0;
    int row[n],col[n];
    int ind=0;
    for (int i=0;i<n;i++){
        int temp=0;
        for (int j=0;j<n;j++){
            temp+=arr[i][j];
        }
        row[ind++]=temp;
        maxval=max(temp,maxval);
    }
    ind=0;
    for (int i=0;i<n;i++){
        int temp=0;
        for (int j=0;j<n;j++){
            temp+=arr[j][i];
        }
        col[ind++]=temp;
        maxval=max(temp,maxval);
    }
    int ans=0;
    for (int i=0;i<n;i++){
        ans+=maxval-row[i];
        ans+=maxval-col[i];
    }
    return ans/2;
}
int main(){
    int matrix[][3] = {{1, 2, 3},
              {4, 2, 3},
              {3, 2, 1}};
    cout << findMinOpeartion(3, matrix);
    return 0;
}