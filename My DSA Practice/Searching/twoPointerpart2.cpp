#include <iostream>
#include <map>
using namespace std;
int getPairsCount(int arr[], int n, int k) {
        int ans=0;
        map <int, int> hash;
        for (int i=0;i<n;i++){
            hash[arr[i]]++;
        }
        for (int i=0;i<n;i++){
            cout << k-arr[i] << " ";
            if (hash[k-arr[i]]>0)
                ans++;
            
        }
        return ans;
    }
int main(){
    // map<int, int> hash;
    // cout << hash[1] << " ";
    // hash.insert({1,2});
    // cout << hash[1];
    int N = 4, K = 6;
    int arr[] = {1, 5, 7, 1};
    cout << getPairsCount(arr, N, K);
    return 0;
}