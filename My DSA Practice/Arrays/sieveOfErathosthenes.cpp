#include <iostream>
#include <vector>
using namespace std;
void sieve1(int n){
    bool arr[n+1]; // or use vector <bool> arr(n+1,true);
    for (int i=0;i<=n;i++){
        arr[i]=true;
    }
    for (int i=2;i*i<=n;i++){
        if (arr[i]){
            for (int j=2*i;j<=n;j+=i){
                arr[j]=false;
            }
        }
    }
    for (int i=2;i<=n;i++){
        if (arr[i])
        cout << i << " ";
    }
}
void sieve2(int n){
    vector<bool>arr(n+1,true);
    for (int i=0;i*i<=n;i++){
    cout << "p";
        if(arr[i]){
            for(int j=i*i;j<=n;j+=i)
            arr[j]=false;
        }
    }
    for (int i=2;i<=n;i++){
        if (arr[i])
        cout << i << " ";
    }
}
int main(){
    sieve2(36);

    return 0;
}