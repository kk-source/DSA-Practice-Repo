#include <iostream>
#include <string>
using namespace std;

// 7*5=35
// 7 14 21 28 35
int lcm (int a, int b){
    int res=max(a,b);
    while(true){
        if (res%a==0 && res%b==0)
        return res;
        res++;
    }
    return 0; // time complexity wiint be O(a*b-max(a,b))
}
// better approach.
int lcm1 (int a, int b){
    int l=min(a,b);
    int h=max(a,b);
    for (int i=h;;i+=h){
        if (i%l==0)
            return i;
    }
    return 0;
}
// best approach is to use gcd technique using the fact a*b=lcm*hcf.
int main(){
    cout << lcm(12,15);

    return 0;
}