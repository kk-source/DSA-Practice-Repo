#include <iostream>
#include <string>
using namespace std;
bool isLucky(int n) {
    static int i=2;
    if (n%i==0)
    return false;
    else if (n<i)
    return true;
    return isLucky(n-n/(i++));
}
int main(){
    cout << isLucky(74) << endl;
    return 0;
}