#include <bits/stdc++.h>
using namespace std;
void frequency(int arr[], int n){ // naive
    for (int i=0;i<n;i++){
        bool flag=false;
        for (int j=0;j<i;j++){
            if (arr[i]==arr[j]){
                flag=true;
                break;
            }
        }
            if (flag)
            continue;
        int count=0;
            for (int j=i;j<n;j++){
                if (arr[j]==arr[i])
                count++;
            }
            cout << arr[i] << " " << count << endl;
        }
}
void frequency1(int arr[], int n){
    unordered_map<int, int> s;
    for (int i=0;i<n;i++){
        s[arr[i]]++;
    }
    // for (auto i : s)
    //     cout << i.first << " " << i.second << endl;

    for (auto i=s.begin();i!=s.end();i++)
        cout << (*i).first << " " << i->second << endl;
}

int main(){
    int arr[]={1,2,3,4,5,1,2,3,6,6,6,74};
    int n=sizeof(arr)/sizeof(arr[0]);
    frequency1(arr, n);
    return 0;
}