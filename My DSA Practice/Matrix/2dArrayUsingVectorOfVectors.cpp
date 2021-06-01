#include <iostream>
#include <vector>
using namespace std;

int main(){
    int r=2,c=3;
    vector<vector<int>> arr;
    for (int i=0;i<r;i++){
            vector<int> temp;
        for (int j=0;j<c;j++)
            temp.push_back(10);
        
        arr.push_back(temp);
    }
    for (int i=0;i<arr.size();i++){
        for (int j=0;j<arr[i].size();j++){
            cout << arr[i][j] << " ";
        }
    }
    return 0;
}