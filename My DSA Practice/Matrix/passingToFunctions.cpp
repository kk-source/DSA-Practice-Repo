#include <iostream>
#include <vector>
using namespace std;
// 1.
void fun(int arr[3][2]){
    for (int i=0;i<3;i++){
        for (int j=0;j<2;j++){
            cout << arr[i][j] << " ";
        }
    }
}
// 2.
void fun1(int arr[][2], int r){
    for (int i=0;i<r;i++){
        for (int j=0;j<2;j++){
            cout << arr[i][j] << " ";
        }
    }
}
// 3.
void fun2(int **arr, int r, int c){
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            cout << arr[i][j] << " ";
        }
    }
}
// 4.
void fun3(int *arr[], int r, int c){
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            cout << arr[i][j] << " ";
        }
    }
}
// 5.
void fun4(vector<int> arr[], int r){
    for (int i=0;i<r;i++){
        for (int j=0;j<arr[i].size();j++){
            cout << arr[i][j] << " ";
        }
    }
}
// 6.
void fun5(vector<vector<int>> &arr){
    for (int i=0;i<arr.size();i++){
        for (int j=0;j<arr[i].size();j++){
            cout << arr[i][j] << " ";
        }
    }
}
int main(){
    int r=3,c=2;
    int arr[3][2]={{1,2},{3,4},{5,6}};
    // fun(arr);

    int **arr1;
    arr1=new int*[r];
    for (int i=0;i<r;i++)
        arr1[i]=new int[c];
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            arr1[i][j]=10;
        }
    }
    // fun2(arr1, r, c);

    int *arr2[r];
    for (int i=0;i<r;i++)
        arr2[i]=new int[c];
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            arr2[i][j]=10;
        }
    }
    // fun3(arr2, r, c);

    vector <int> arr3[r];
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++)
        arr3[i].push_back(10);
    }
    // fun4(arr3, r);

    vector <vector <int>> arr4;
    for (int i=0;i<r;i++){
        vector<int> temp;
        for (int j=0;j<c;j++){
            temp.push_back(10);
        }
        arr4.push_back(temp);
    }
    fun5(arr4);
    return 0;
}