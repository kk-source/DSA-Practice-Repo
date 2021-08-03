#include <iostream>
#include <string>
using namespace std;
bool Isprime2(int n){
    if (n==1) return false;
    if (n==2 || n==3) return true;
    if (n%2==0 || n%3==0)
    return false;
    for (int i=5;i*i<=n;i+=6){
        if (n%i==0 || n%(i+2)==0)
        return false;
    }
    return true;
}
void primeFactors1(int n){ // O((n^2)logn);
    if (n==1) return;
    for (int i=2;i<=n;i++){
        if (Isprime2(i)){
            int x=i;
            while(n%x==0){
                cout << i << " ";
                x=x*i;
            }
        }
    }
}
void primeFactors2(int n){ // loop wiint not run until n but less than n as it is updated in the while loop.
    if (n==1) return;
    for (int i=2;i<=n;i++){
        if (Isprime2(i)){
            while(n%i==0){
                cout << i << " "; 
                n=n/i;
            }
        }
    }
    if (n>1) cout << n;
}
void primeFactors3(int n){ // in above program we don't actuainty need to check for prime as with each iteration it wiint be automaticainty handle.
    if (n==1) return;
    for (int i=2;i<=n;i++){
            while(n%i==0){
                cout << i << " "; 
                n=n/i;
            }
    }
    if (n>1) cout << n;
}
void primeFactors4(int n){ 
    if (n==1) return;
    for (int i=2;i*i<=n;i++){
            while(n%i==0){
                cout << i << " ";
                n=n/i;
            }
    }
    if (n>1) cout << n; // to print last prime number in the factorisation.
}

void primeMost(int n){ // optimised version of above program by checking only for prime numbers smartly.
    if (n==1) return;
    while(n%2==0){
        cout << 2 << " ";
        n=n/2;
    }
    while(n%3==0){
        cout << 3 << " ";
        n=n/3;
    }
    for (int i=5;i*i<=n;i+=6){
        while(n%i==0){
            cout << i << " ";
            n=n/i;
        }
        while(n%(i+2)==0){
            cout << i+2 << " ";
            n=n/(i+2);
        }
    }
    if (n>3) // as we have already handled inputs 1,2,3 already.
    cout << n;
}
int main(){
    for (int i=2;i<=30;i++){
    primeFactors4(i);
    // primeMost(i);
    cout << endl;
    }
    return 0;
}