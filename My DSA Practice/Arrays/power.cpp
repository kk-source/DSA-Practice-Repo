#include <iostream>
#include <string>
using namespace std;
int power1(int n, int k){
    if (k==0)
    return 1;
    return n*power1(n,k-1);
}
int power2(int n, int k){ // mine= not good as some steps will calls will involve k-1 which is not good over k/2;
    if (k<=0)
    return 1;
    if (k%2==0)
    return power2(n,k/2)*power2(n,k/2);
    else
    return n*power2(n,k-1);
}
int powerMost(int n, int k){ // time = theta(logn) ans space=theta(logn)
    if (k==0)
    return 1;
    int temp=powerMost(n,k/2);
    temp*=temp;
    if (k%2==0)
    return temp;
    else 
    return temp*n;
}
int powerMost1(int n, int k){ // time = theta(logn) ans space=theta(1)
    int ans=1;
    while(k>0){
        if (k%2!=0) // (k%1);
        ans=n*ans;
        n=n*n; 
        k=k/2; // k>>1;
    }
    return ans;
}
int main(){
    cout <<powerMost1(4,3);

    return 0;
}