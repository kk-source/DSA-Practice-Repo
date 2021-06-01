#include <iostream>
#include <string>
using namespace std;
void iPartition(int arr[], int n, int l, int h){
    int low=0, i=0, high=n-1;
    while(i<=high){
        if (arr[i]<l){
            swap(arr[i], arr[low]);
            low++;
            i++;
        }
        else if (arr[i]>=l && arr[i]<=h){
            i++;
        }
        else if (arr[i]>h){
            swap(arr[i],arr[high]);
            high--;
        }
    }
}
int main(){
    int arr[]={10,5,6,3,20,9,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    // iPartition(arr, n, 5, 10);
    // for (int i:arr){
    //     cout << i << " ";
    // }
    // cout << (char)98 << " ";
    string p ;
    p+= 'a';
    // p+=(char)98;
    cout << p;
    return 0;
}