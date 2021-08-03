#include <iostream>
#include <string>
using namespace std;

bool Isprime(ll n){
    for (ll i=2;i<n;i++){
        if (n%i==0)
        return false; 
    } // time complexity is O(n).
    return true;
}
// better approach
bool Isprime1(ll n){
    if (n==1){
        return false;
    }
    for (ll i=2;i*i<=n;i++){
        if (n%i==0)
        return false;
    }
    return true;
}
// best approach of all.
bool Isprime2(ll n){
    if (n==1) return false;
    if (n==2 || n==3) return true;
    if (n%2==0 || n%3==0)
    return false;
    for (ll i=5;i*i<=n;i+=6){
        if (n%i==0 || n%(i+2)==0)
        return false;
    }
    return true;
}
ll main(){
    cout << Isprime2(1031);
    return 0;
}