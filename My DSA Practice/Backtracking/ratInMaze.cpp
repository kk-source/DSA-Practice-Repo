#include <bits/stdc++.h>
using namespace std;

bool safe(int i, int j, int n, vector<vector<int>> arr){
    return (i<n && j<n && arr[i][j]==1);
}
bool fun(vector<vector<int>> arr, vector<vector<int>> &temp, int i=0, int j=0){
    if (i==arr.size()-1 && j==arr.size()-1 && arr[i][j]){
        temp[i][j]=1;
        return true;
    }
    if (safe(i, j, arr)){
    temp[i][j]=1;
    if (safe(i+1, j, arr.size(), arr) && fun(arr, temp, i+1, j)){
        return true;
    }
    if (safe(i, j+1, arr.size(), arr) && fun(arr, temp, i, j+1))
    return true;
    temp[i][j]=0;
    }
    return false;
}
void print(vector<vector<int>> temp){
    int n=temp.size();
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            cout << temp[i][j] << " ";
        cout << endl;
    }
}
bool maze(vector<vector<int>> arr){
    vector<vector<int>> temp;
    int n=arr.size();
    for (int i=0;i<n;i++){
        vector<int> temp1;
        for (int j=0;j<n;j++)
        temp1.push_back(0);
        temp.push_back(temp1);
    }
    if (fun(arr, temp)){
        print(temp);
        return true;
    }
    return false;
}
int main(){
    vector<vector<int>> arr={{1, 0, 0}, 
                            {0, 1, 0},
                            {1, 1, 1}};
    cout << maze(arr);
    return 0;
}