#include <iostream>
#include <string>
using namespace std;
bool check(int n, int k){
    // cout << "p";
    if (1&(n>>(k-1))==0)
    return false;
    else
    return true;
}
bool check1(int n, int k){
    // cout << "p";
    if (n&(1<<(k-1))==0)
    return false;
    else
    return true;
}
int main(){
    cout << check1(5,3);
    // cout << ((5>>7)&1);
    return 0;
}