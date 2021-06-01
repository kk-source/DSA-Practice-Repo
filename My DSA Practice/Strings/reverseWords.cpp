#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void reverse(string &str, int start, int end){
    while(start<=end){
        swap(str[start], str[end]);
        start++;
        end--;
    }
}
void rev(string &str){
    int start=0, n=str.size();
    for (int end=0;end<n;end++){
        if (str[end]==' '){
            reverse(str, start, end-1);
            // reverse(str.begin()+start, str.begin()+end);
            start=end+1;
        }
    }
    // reverse(str, start, n-1);
    reverse(str.begin()+start, str.begin()+n);
    // reverse(str, 0, n-1);
    reverse(str.begin(), str.begin()+n);
}
int main(){
    string str="I love my country";
    // string str="abc";
    rev(str);
    cout << str;
    return 0;
}