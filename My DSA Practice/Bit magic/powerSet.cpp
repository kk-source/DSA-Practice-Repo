#include <iostream>
#include <string>
#include <cmath>
using namespace std;
void print(string str){
    int n=str.size();
    int powsize=pow(2,str.size());
    for (int i=0;i<powsize;i++){
        for (int j=0;j<n;j++){
            if ((i&(1<<j))!=0)
            cout << str[j];
        }
        cout << endl;
    }
}
int main(){
    string str="abc";
    // print(str);  
    // cout << 0xAAAAAAAA;
    cout << 0x55555555;
    return 0;
}