#include <bits/stdc++.h>
using namespace std;
void findPairs(int arr[], int n) 
    {
        vector<int> ans;
        unordered_set<int> s(arr, arr+n);
        unordered_set<int> temp;
        for (int i=0;i<n;i++){
            temp.insert(arr[i]);
            if (temp.find(arr[i])!=temp.end() && temp.find(-arr[i])!=temp.end()){
                if (arr[i]<0){
                    ans.push_back(arr[i]);
                    ans.push_back(-arr[i]);
                }
                else if (arr[i]>0){
                    ans.push_back(-arr[i]);
                    ans.push_back(arr[i]);
                }
                temp.erase(arr[i]);
                temp.erase(-arr[i]);
            }
        }
        for (auto i:ans)
        cout << i << " ";
    }
int main(){
    int arr[]={-12, 54, -48, -3, 39, -21, 0, -14 ,-7, 47 ,86 ,-66 ,-41 ,-71, -51 ,83, 59, 5, -23 ,-35, -83 ,-8 ,-99 ,-75 ,-77 ,-39 ,23 ,56 ,24 ,95 ,-13, -16, -11, -37, 42, 1, -10 ,28 ,-44 ,-25, -2, 45, 66 ,-74, 60, -72 ,-82 ,46 ,94 ,-15 ,-89 ,71 ,48 ,29, 16, 20 ,34 ,81 ,-42, 87, 75 ,-98 ,92 ,-49, -30 ,-58 ,-28 ,-26 ,-69 ,-22 ,98 ,78 ,-19, 41};
    int n=sizeof(arr)/sizeof(arr[0]);
    findPairs(arr, n);
    return 0;
}