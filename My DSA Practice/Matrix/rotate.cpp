#include <iostream>
using namespace std;

void fun1(int **arr, int n){
    int temp[n][n];
    int col=n-1;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            temp[i][j]=arr[j][col]; // can replace col with n-1-i also.
        }
        col--;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            arr[i][j]=temp[i][j];
        }
    }
}
void fun2(int **arr, int n){
    int end=1;
    //transpose
    for (int i=1;i<n;i++){
        int start=0;
        while(start<end){
        swap(arr[start][end],arr[end][start]);
        start++;
        }
        end++;
    }
    //reverse
    int top=0,bottom=n-1;
    while(top<bottom){
        for (int i=0;i<n;i++){
            swap(arr[top][i],arr[bottom][i]);
        }
        top++;
        bottom--;
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
    fun2(arr, r);
    for (int i=0;i<r;i++){
        for (int j=0;j<r;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}