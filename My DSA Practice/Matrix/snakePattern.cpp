#include <iostream>
#include <string>
using namespace std;
void fun1(int **arr, int r, int c){
    for (int i=0;i<r;i++){
        if (i%2==0){
            for(int j=0;j<c;j++)
            cout << arr[i][j] << " ";
        }
        else
            for (int j=c-1;j>=0;j--)
            cout << arr[i][j] << " ";
    }
}

int main(){
    int r=3,c=4;
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