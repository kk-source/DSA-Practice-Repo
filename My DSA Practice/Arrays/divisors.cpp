#include <iostream>
#include <string>
using namespace std;
void divisors(int n){
    for (int i=1;i<=n;i++){
        if (n%i==0)
        cout << i << " ";
    }
}
void divisors1(int n){
    for (int i=1;i*i<=n;i++){
        if (n%i==0){
                cout << i << " ";
            if(i!=n/i)
            cout << n/i << " ";
        }
    }
}
void divisorsMost(int n){ // using above method to print in sorted manner.
    int i;
    for (i=1;i*i<n;i++){
        if (n%i==0){
            cout << i << " ";
        }
    }
    for (;i>=1;i--){
        if (n%i==0){
            cout << n/i << " ";
        }
    }
}
int main(){
    divisors1(25);
    cout <<endl;
    divisorsMost(25);
    return 0;
}