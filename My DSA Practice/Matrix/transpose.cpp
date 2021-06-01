#include <iostream>
using namespace std;

void fun2(int **arr, int r, int c){ // only for square matrix.
    int end=1;
    for (int i=1;i<r;i++){
        int start=0;
        while(start<end){
        swap(arr[start][end], arr[end][start]);
        start++;
        }
        end++;
    }
}

int main(){
    int r=4,c=4;
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
    fun2(arr, r,c);
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}