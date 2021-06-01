#include <iostream>
#include <string>
using namespace std;
void tower(int n, char a='A', char b='B', char c='C'){
    //if (n==0)
    //return;
    if (n==1){
    cout << "move 1 from " << a << " to " << c << endl;
    return;
    }
    tower(n-1, a, c, b);
    cout << "move " << n << " from " << a << " to " << c << endl;
    tower(n-1, b, a, c);
}
int main(){
    tower(3);

    return 0;
}