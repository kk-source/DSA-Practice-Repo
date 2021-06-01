#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void bucketsort(int arr[], int n, int k){
    int maxval=arr[0];
    for (int i=1;i<n;i++){
        maxval=max(maxval,arr[i]);
    }
    maxval++;
    vector<int> buk[k];
    for(int i=0;i<n;i++){
        int bi=(k*arr[i])/maxval;
        buk[bi].push_back(arr[i]);
    }
    for (int i=0;i<k;i++)
        sort(buk[i].begin(),buk[i].end());
    
    int index=0;
    for (int i=0;i<k;i++)
        for (int j=0;j<buk[i].size();j++)
            arr[index++]=buk[i][j];
}
int main(){
    int arr[]={20,88,10,85,75,95,18,82,60};
    int n=sizeof(arr)/sizeof(arr[0]);
    bucketsort(arr, n, 5);
    for (int i: arr)
    cout << i << " ";
    return 0;
}