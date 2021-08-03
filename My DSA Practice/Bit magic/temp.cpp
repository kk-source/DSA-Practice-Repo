#include <iostream>
#include <string>
using namespace std;
int maxAND (int arr[], int N)
    {
        int pos=31;
        int ans=0;
        while(pos!=-1){
            int count=0;
            int temp=(ans|(1<<pos));
            for (int j=0;j<N;j++){
                if ((arr[j]&temp)==temp)
                count++;
            }
            if (count>1){
            ans=temp;
            cout << pos << " ";
            }
            pos--;
        }
        return ans;
    }
int main(){
    int arr[]={12,13,14,15,16,17,18};
    int n=sizeof(arr)/sizeof(int);
    cout << maxAND(arr, n);

    return 0;
}