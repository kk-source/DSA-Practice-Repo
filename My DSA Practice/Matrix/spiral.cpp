#include <iostream>
using namespace std;

void fun(int **arr, int r, int c){

    int top=0,bot=r-1,left=0,right=c-1;
    while(top<=bot && left<=right){
        
        for (int i=left;i<=right;i++)
            cout << arr[top][i] << " ";
        top++;
        
            for (int i=top;i<=bot;i++)
            cout << arr[i][right] << " ";
        right--;
        
        if (top<=bot){ // as top has incremented in above steps so it is possible that is has exceeded bottom.
            for (int i=right;i>=left;i--)
            cout << arr[bot][i] << " ";
        bot--;
        }

        if (left<=right){ // as right has decremented in above steps so it is possible that is has become less than left.
            for (int i=bot;i>=top;i--)
            cout << arr[i][left] << " ";
        left++;
        }   

    }
}
int main(){ // corner case is 1 2 or 2 1.
    int r=1,c=2;
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
    fun(arr, r,c);

    return 0;
}