#include <iostream>
#include <string>
using namespace std;

int main(){
    int *p;
    p=new int[4];
    for (int i=0;i<4;i++){
        *p=(i+1);
        p++;
    }
    p--;
    for (int i=0;i<4;i++){
        cout << *p << " ";
        p--;
    }
    return 0;
}