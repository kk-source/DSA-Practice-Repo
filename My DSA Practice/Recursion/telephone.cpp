#include <bits/stdc++.h>
using namespace std;

string str[]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
 vector<string> possibleWords(int a[], int N)
        {
            vector<string> temp;
            if (N==1){
                for (int i=0;i<str[a[0]].size();i++){
                    string tem="";
                    // tem.push_back(str[a[0]][i]);
                    tem+=str[a[0]][i];
                    temp.push_back(tem);
                }
                return temp;
            }
            for (int i=0;i<str[a[0]].size();i++){
                vector<string> tmp = possibleWords(a+1,N-1);
                for (int j=0;j<tmp.size();j++)
                    temp.push_back(str[a[0]][i]+tmp[j]);
            }
            return temp;
        }
void possibleWords1(int a[], int N, string temp=""){
    if (N==1){
        for (int i=0;i<str[a[0]].size();i++)
        cout << temp+str[a[0]][i] << endl;
        return;
    }
    // if (N==0){
        // cout << temp << endl;
        // return;
    // }
    for (int i=0;i<str[a[0]].size();i++)
        possibleWords1(a+1,N-1,temp+str[a[0]][i]);
}
int main() {
    int arr[]={2,3,4};
    int n=3;
    // vector<string> temp=possibleWords(arr,n);
    // for (auto i: temp)
    // cout << i << endl;
    // possibleWords1(arr, n);
    // cout << (1 << 32);
    int a=-3;
    cout << (a>>32);
    return 0;
}