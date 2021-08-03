#include <bits/stdc++.h>
using namespace std;

bool safe(int row, int col, int n, vector<vector<int>> temp){
    for (int i=0;i<col;i++){
        if (temp[row][i]==1)
        return false;
    }
    for (int i=row, j=col;i>=0 && j>=0;j--, i--){
        if (temp[i][j]==1)
        return false;
    }
    for (int i=row, j=col;i<n && j>=0;j--, i++){
        if (temp[i][j]==1)
        return false;
    }
    return true;
}
bool fun(int col, vector<vector<int>> &temp){
    int n=temp.size();
    if (col==n)
    return true;
    for (int j=0;j<n;j++){
        if (safe(j, col, n, temp)){
            temp[j][col]=1;
            if (fun(col+1, temp)){
            return true;
            }
            temp[j][col]=0;
        }
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
bool queen(int n){
    if (n<=3)
    return false;
    vector<vector<int>> temp;
    for (int i=0;i<n;i++){
        vector<int> temp1;
        for (int j=0;j<n;j++)
        temp1.push_back(0);
        temp.push_back(temp1);
    }
    if (fun(0, temp)==false)
    return false;

    print(temp);
    return true;
}
int main(){
    int n=10;
    cout << queen(n);
    return 0;
}