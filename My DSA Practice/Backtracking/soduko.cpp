#include <bits/stdc++.h>
using namespace std;

bool safe(int i, int j, int n, vector<vector<int>> arr){
    for (int k=0;k<arr.size();k++){
        if (arr[i][k]==n || arr[k][j]==n)
        return false;
    }
    int root=sqrt(arr.size());
    int rs=i-i%root;
    int cs=j-j%root;
    for (int x=rs;x<root+rs;x++){
        for (int y=cs;y<cs+root;y++){
            if (arr[x][y]==n)
            return false;
        }
    }
    return true;
}

void print(vector<vector<int>> temp){
for (int i=0;i<temp.size();i++){
for (int j=0;j<temp.size();j++)
cout << temp[i][j] << " ";
cout << endl;
}
}

bool fun(vector<vector<int>> &arr){
    int n=arr.size();
    int i, j;
    bool flag=false;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (arr[i][j]==0){
                for (int k=1;k<=n;k++){
                    if (safe(i, j, k, arr)){
                        arr[i][j]=k;
                        if (fun(arr))
                        return true;
                        arr[i][j]=0;
                    }
                }
                flag=true;
                break;
            }
        }
        if (flag)
        break;
    }
    if (i==n)
    return true;
    return false;
}
bool soduko(vector<vector<int>> &arr){
    if (fun(arr)){
        print(arr);
        return true;
    }
    return false;
}
int main(){
    vector<vector<int>> arr={{1, 0, 3, 0},
                            {0, 0, 2, 1},
                            {0, 1, 0, 2}, 
                            {2, 4, 0, 0}};
    cout << soduko(arr);
    return 0;
}