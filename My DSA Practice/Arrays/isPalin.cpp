#include <iostream>
#include <string>
using namespace std;
int isPalin(int n){
    string temp="";
    temp+=to_string(n);
    for (int i=0;i<temp.size()/2;i++){
        if (temp[i]!=temp[temp.size()-1-i]){
            return 0;
        }
    }
    return 1;
}
int isPalin1(int n){
    int temp=n;
    int rev=0;
    while(temp>0){
        rev=rev*10+temp%10;
        temp=temp/10;
    }
    if (rev==n)
    return 1;
    else return 0;
}
int main(){
    cout << "Enter the number" << endl;
    int test;
    cin>>test;
    if(isPalin1(test))
        cout << "yes" << endl;
    else
    cout << "no" << endl;

    return 0;
}