#include <iostream>
using namespace std;

void fun(int **arr, int r, int c, int key){ // from bottom left.
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        cout << arr[i][j] << " ";
        cout << endl;
    }
    int row=r-1,col=0;
    while(row>=0 && col<c){
        if (key<arr[row][col])
            row--;
        else if (key>arr[row][col])
            col++;
        else if (key==arr[row][col]){
            cout << "found at " << row << "," << col; 
            return;
        }
    }
    cout << "not found";
}
void fun1(int **arr, int r, int c, int key){ // from right top.
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        cout << arr[i][j] << " ";
        cout << endl;
    }
    int row=0,col=c-1;
    while(row<r && col>=0){
        if (key<arr[row][col])
            col--;
        else if (key>arr[row][col])
            row++;
        else if (key==arr[row][col]){
            cout << "found at " << row << "," << col; 
            return;
        }
    }
    cout << "not found";
}

int main(){
    int r=4,c=4;
    int **arr;
    arr=new int *[r];
    for (int i=0;i<r;i++){
        arr[i]=new int [c];
    }
    // int count=1;
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++)
            arr[i][j]=i+j+1;
    }
    fun(arr, r, c, 4);
    return 0;
}