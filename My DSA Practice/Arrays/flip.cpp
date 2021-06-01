#include <iostream>
#include <string>
using namespace std;
void flip(int arr[], int n){
    int ones=0;
    int zeroes=0;
    bool flag=true;
    for (int i=0;i<n;i++){
        if (arr[i]==1 && flag){
            ones++;
            flag=false;
        }
        else if (arr[i]==0 && flag){
            zeroes++;
            flag=false;
        }
        if (arr[i]!=arr[i+1]){
        flag = true;
        }
    }
    // cout << ones << " " << zeroes;
    flag=true;
    
    for (int i=0;i<n;i++){
        if(zeroes<ones){
            if (arr[i]==0 && flag){
            cout << "From " << i << " to ";
            flag=false;
            }
            if (arr[i]!=0 && !flag){
                cout << i-1 << endl;
                flag=true;
            }
        }
        else{
            if (arr[i]==1 && flag){
                cout << "From " << i << " to ";
                flag=false;
            }
            if (arr[i]!=1 && !flag){
                cout << i-1 << endl;
                flag=true;
            }
        }
    }
}
int main(){
    int arr[]={1,1,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    flip(arr,n);

    return 0;
}