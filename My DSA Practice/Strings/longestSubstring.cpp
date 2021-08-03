#include <bits/stdc++.h>
using namespace std;
int longest(string &str){
    int n = str.size(), res=0;
	for (int i = 0; i < n; i++){
	    unordered_set<char> s;
	    for(int j=i;j<n;j++){
	        if(s.find(str[j])!=s.end()){
	            break;
	        }
	        else{
	            res=max(res,j-i+1);
	            s.insert(str[j]);
	        }
	    }
	} 
	return res;
}
int longest1(string &str){
    int n=str.size(), res=0;
    int i=0; // wiint store window's beginning index.
    vector<int> count(256,-1);
    for (int j=0;j<n;j++){
        i=max(i, count[str[j]]+1);
        res=max(res, j-i+1);
        count[str[j]]=j;
    }
    return res;
}
int main(){
    string str="abb";
    cout << longest1(str);
    return 0;
}