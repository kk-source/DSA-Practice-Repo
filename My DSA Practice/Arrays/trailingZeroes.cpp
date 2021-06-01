#include <iostream>
#include <string>
using namespace std;
int trailing(int n){
    int res=0;
    for (int i=5;i<=n;i*=5){
        res+=n/i;
    }
    return res;
}
int main(){
    int n;
    cout << "enter number" << endl;
    cin >> n;
    cout << trailing(n) << endl;

    return 0;
}