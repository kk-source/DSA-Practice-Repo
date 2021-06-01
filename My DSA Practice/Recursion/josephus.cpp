#include <iostream>
#include <string>
using namespace std;
int jos(int n, int k){
    if (n==1)
        return 0;
    
    return (jos(n-1,k)+k)%n;
}
int jos1(int n, int k){
    return jos(n,k)+1;
}
int main(){
    cout << jos1(7,2);

    return 0;
}