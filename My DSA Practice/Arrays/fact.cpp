#include <iostream>
#include <string>
using namespace std;
long long int fact(int n){
    long long int ans=1;
    // for (int i=2;i<=n;i++)
    for (int i=n;i>1;i--)
    ans*=i;
    return ans;
}
long long int fact1(int n){
    if (n==1)
    return 1;
    return n*fact1(n-1);
}
int main(){
    int n;
    cout << "enter number" << endl;
    cin >> n;
    cout << fact1(n);

    return 0;
}