#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> temp){
for (int i=0;i<temp.size();i++){
for (int j=0;j<temp.size();j++)
cout << temp[i][j] << " ";
cout << endl;
}
}

bool check1(int i, int j, vector<vector<int>> temp){
int n=temp.size();
for (int k=0;k<n;k++){
if (temp[i][k] || temp[k][j])
return false;
}
for (int k=i, l=j;k<n && l<n;k++, l++){
if (temp[k][l])
return false;
}
for (int k=i, l=j;k>=0 && l>=0;k--, l--){
if (temp[k][l])
return false;
}
for (int k=i, l=j;k>=0 && l<n;k--, l++){
if (temp[k][l])
return false;
}
for (int k=i, l=j;k<n && l>=0;k++, l--){
if (temp[k][l])
return false;
}
return true;
}

bool fun(int n, int count, vector<vector<int>> &temp){
if (count==n)
return true;
for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
            if (temp[i][j]==0 && check1(i, j, temp)){
            temp[i][j]=1;
            if (fun(n, count+1, temp))
            return true;
            temp[i][j]=0;
            }
    }
}
return false;
}

bool queen(int n){

vector<vector<int>> temp;
for (int i=0;i<n;i++){
vector<int> temp1;
for (int j=0;j<n;j++)
temp1.push_back(0);
temp.push_back(temp1);
}

if (fun(n, 0, temp)){
print(temp);
return true;
}
return false;
}
int main()
{
    int n=10;
    cout << queen(n);
    return 0;
}