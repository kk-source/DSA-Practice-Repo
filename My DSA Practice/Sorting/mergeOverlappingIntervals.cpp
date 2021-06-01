#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
bool mycmp(pair<int, int> a1, pair<int, int> a2){
    return (a1.first<a2.first);
}
void merge(pair<int, int> arr[], int n){
    sort(arr, arr+n, mycmp);
    int res=0;
    for (int i=1;i<n;i++){
        if (arr[i].first<=arr[res].second){
            arr[res].first=min(arr[i].first,arr[res].first);
            arr[res].second=max(arr[i].second,arr[res].second);
        }
        else{
            res++;
            arr[res]=arr[i];
        }
    }
    for (int i=0;i<=res;i++){
        cout << arr[i].first << " " << arr[i].second << endl;
    }
}
int main(){
    pair <int, int> arr[]={{1,3}, {2,4}, {5,7}, {6,8}};
    // pair <int, int> arr[]={{1,3}, {2,4}, {4,5}, {7,9}, {6,10}};
    int n=sizeof(arr)/sizeof(arr[0]);
    merge(arr, n);
    return 0;
}