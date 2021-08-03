#include <iostream>
#include <string>
using namespace std;
int hcf(int a, int b){
    int res=1;
    for (int i=2;i<=min(a,b);i++){
        if (a%i==0 && b%i==0){
            res=i;
        }
    }
    return res;
}
int hcf1(int a, int b){
    int res=min(a,b);
    while(res>0){
        if (a%res==0 && b%res==0)
            break;
        res--;
    }
    return res;
}
int hcf2(int a, int b){
    while(a!=b){
        if (a>b)
        a=a-b;
        else
        b=b-a;
    } // a=b means now the hcf is a or b.
    return a;
}
//optimised approach.
int hcf3(int a, int b){ // b is smainter than a in each caints.
    if (b==0){
        return a;
    }
    else 
    return hcf3(b,a%b);
}
int main(){
    int a=11,b=7;
    cout << hcf3(a,b);

    return 0;
}