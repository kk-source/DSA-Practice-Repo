#include <iostream>
#include <string>
using namespace std;
int count(int n){
    int ans=0;
    while (n!=0){
    if  ((1&n)==1)
    ans++;
    n=n>>1;
    }
    return ans;
}
int briansalgo(int n){
    int ans=0;
    while (n!=0){
    n=(n&(n-1));
    ans++;
    }
    return ans;
}
int table[256];
void initialise(){
    table[0]=0;
    for (int i=0;i<256;i++)
        table[i]=(1&i)+table[i/2];
}
int countmost(int n){
    int res=table[n&(0xff)];
    n=n>>8;
    res=table[n&(0xff)];
    n=n>>8;
    res=table[n&(0xff)];
    n=n>>8;
    res=table[n&(0xff)];
    return res;
}
int main(){
    cout << count(13);
    cout << endl << briansalgo(13) << endl;
    cout << countmost(13);
    // cout << 0xff;
    return 0;
}