#include <iostream>
#include <vector>
using namespace std;
void linearProbing(int hashSize, int arr[], int sizeOfArray)
    {
        vector<int> ans(hashSize,-1);
        for(int i=0;i<sizeOfArray;i++)
        {
            int index = arr[i]%hashSize;
            while(ans[index] != -1){   
                if(ans[index] == arr[i] ) 
                    break;
                index = (index+1)%hashSize;
                if (index == (arr[i]%hashSize)) break; 
            }
            if(ans[index] == -1)
                ans[index] = arr[i];
        }
        for (auto i:ans)
        cout << i << " ";
    }
int main(){
    int arr[]={4, 1, 2, 3, 4};
    int n=sizeof(arr)/sizeof(arr[0]);
    linearProbing(5, arr, n);
    return 0;
}