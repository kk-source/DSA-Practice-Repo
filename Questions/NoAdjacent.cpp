#include <iostream>
#include <vector>
using namespace std;
// Maximum sum such that no two elements are adjacent.
/*
Input : arr[] = {5, 5, 10, 100, 10, 5}
Output : 110

Input : arr[] = {1, 2, 3}
Output : 4

Input : arr[] = {1, 20, 3}
Output : 20
*/
int Maximum(vector<int> arr, int n){
    int exc=0;
    int inc=arr[0];
    int ans=0;
    for (int i=1;i<n;i++){
        int exc_new=max(exc, inc);
        inc=arr[i]+exc;
        exc=exc_new;
    }
    return max(inc, exc);
}
int main(){
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    cout<<Maximum(arr, arr.size());
    return 0;
}