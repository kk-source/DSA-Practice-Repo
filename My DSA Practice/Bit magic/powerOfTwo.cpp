#include <iostream>
using namespace std;

bool power(int n){
    if (n==0)
    return false;
    while(n!=1){
        if (n%2!=0)
        return false;
        n=n/2;
    }
    return true;
}
bool powermost(int n){
    if (n==0)
    return false;
    return ((n&(n-1))==0);
}
int main(){
    cout << power(2);

    return 0;
}