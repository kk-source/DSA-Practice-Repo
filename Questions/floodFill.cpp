#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &image, int i, int j, int pcol, int newc){
    if (i>=0 && j>=0 && i<image.size() && j<image[0].size() && image[i][j]==pcol){
        image[i][j]=newc;
        dfs(image, i+1, j, pcol, newc);
        dfs(image, i-1, j, pcol, newc);
        dfs(image, i, j+1, pcol, newc);
        dfs(image, i, j-1, pcol, newc);
    }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (newColor!=image[sr][sc])
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
int main(){
    vector<vector<int>> v={{1,1,1,1,1}};
    auto t=floodFill(v, 0, 1, 2);
    for (int i=0;i<t.size();i++){
        for (int j=0;j<t[i].size();j++){
        cout << t[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}