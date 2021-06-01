#include <iostream>
#include <string>
using namespace std;

int main(){
    int r=3,c=2;
    int **arr;
    arr=new int*[r]; // on heap.
    for (int i=0;i<r;i++)
        arr[i]=new int [c]; // on heap.
    
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            arr[i][j]=10;
            cout << arr[i][j] << " ";
        }
    }

    return 0;
}