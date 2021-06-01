#include <iostream>
#include <map>
using namespace std;
int firstRepeated(int arr[], int n) {
        map<int, int> temp;
        for (int i=0;i<n;i++){
            temp[arr[i]]++;
        }
        for (int i=0;i<n;i++){
            if (temp[arr[i]]>1){
            return i+1;
            }
        }
        return -1;
    }
int main(){
    int arr[]={1,2,3,4,2,4,6,3};
    int n=8;
    cout << firstRepeated(arr, n);
    return 0;
}