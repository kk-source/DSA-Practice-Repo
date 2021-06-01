#include <iostream>
using namespace std;

void fun1(int **arr, int r, int c){
    if (r==1){
        for (int i=0;i<c;i++)
            cout << arr[0][i] << " ";
        return;
    }
    else if (c==1){
        for (int i=0;i<r;i++)
            cout << arr[i][0] << " ";
        return;
    }
    for (int i=0;i<c;i++){
        cout << arr[0][i] << " ";
    }
    for (int i=1;i<r;i++){
        cout << arr[i][c-1] << " ";
    }
    for (int i=c-2;i>=0;i--){
        cout << arr[r-1][i] << " ";
    }
    for (int i=r-2;i>=1;i--){
        cout << arr[i][0] << " ";
    }
}

int main(){
    int r=3,c=2;
    int **arr;
    arr=new int *[r];
    for (int i=0;i<r;i++){
        arr[i]=new int [c];
    }
    int count=1;
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++)
            arr[i][j]=count++;
    }
    fun1(arr, r,c);

    return 0;
}