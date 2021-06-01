#include <iostream>
#include <string>
using namespace std;
void pattern(string str, string ptr){
    int n=str.size(), m=ptr.size();
    for (int i=0;i<=n-m;i++){
        int j;
        for (j=0;j<m;j++)
            if (str[i+j]!=ptr[j])
                break;
        
        if (j==m)
            cout << i << " ";
    }
}
void pattern1(string str, string ptr){ // for distinct.
    int n=str.size(), m=ptr.size();
    for (int i=0;i<=n-m;){
        int j;
        for (j=0;j<m;j++)
            if (str[i+j]!=ptr[j])
                break;
        
        if (j==m)
            cout << i << " ";
        if (j==0)
            i++;
        else
            i+=j;
    }
}
int main(){
    // string str="abababcd";
    // string ptr="abab";
    string str="abcabcd";
    string ptr="abcd";
    // string str="aaaaa";
    // string ptr="aaa";
    pattern1(str, ptr);
    return 0;
}