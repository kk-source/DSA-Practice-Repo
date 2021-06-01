#include <iostream>
#include <string>
using namespace std;
void oddAppearing(int arr[], int n)
{
    
        int xors = 0, res1 = 0, res2 = 0; 
        
        for (int i = 0; i < n; i++) 
        xors = xors ^ arr[i]; 
  
   
        int sn = xors & (~(xors - 1)); 
  
    
        for (int i = 0; i < n; i++) 
        { 
            if ((arr[i] & sn) == 0) 
                res1 = res1 ^ arr[i]; 
            else
                res2 = res2 ^ arr[i]; 
        } 
        
        
        cout <<  res1 << " " << res2;
}
int main(){
    int arr[]={3,4,3,4,8,4,4,32,7,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    oddAppearing(arr, n);
    return 0;
}