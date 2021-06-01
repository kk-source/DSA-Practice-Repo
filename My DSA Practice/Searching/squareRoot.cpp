#include <iostream>
#include <string>
using namespace std;
int sqrtfloor(int n){
    int i=1;
    while(i*i<=n)
        i++;
    return i-1;
}
int sqrtbin(int n){
    int low=1, high=n;
    int ans=0;
    while(low<=high){
        int mid=(high+low)/2;
        int msq=mid*mid;
        if (msq==n)
        return mid;
        else if (msq>n)
        high=mid-1;
        else{
            ans=mid;
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    int k; cin >> k;
    cout << sqrtbin(k);

    return 0;
}