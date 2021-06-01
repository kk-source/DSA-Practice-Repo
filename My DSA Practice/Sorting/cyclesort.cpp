#include <iostream>
using namespace std;
void cycle(int arr[], int n){
    int ans=0;
    for (int i=0;i<n-1;i++){
        int item=arr[i], pos;
        do{
            pos=i;
            for (int j=i+1;j<n;j++){
                if (arr[j]<item)  // if (arr[i]<item)
                pos++;
            }
            while(item==arr[pos] && pos!=i)
            pos++;                // pos++;
            swap(arr[pos],item);
            ans += pos != i;
        }while(pos!=i);
    }
    cout << ans;
}
int main(){
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cycle(arr, n);
    // for (int i : arr)
    // cout << i << " ";

    return 0;
}