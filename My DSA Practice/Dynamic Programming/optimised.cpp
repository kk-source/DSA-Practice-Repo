#include <iostream>
#include <string>
using namespace std;
int lcs(string s1, string s2)
{
    int n=s1.size(), m=s2.size();
    int arr[2][m+1];

    for (int i=0;i<=m;i++)
    arr[0][i]=0;

    for (int j=1;j<=n;j++)
    {
        arr[j%2][0]=0;
    for (int i=1;i<=m;i++){
        if (s1[j-1]==s2[i-1])
            arr[j%2][i]=1+arr[(j-1)%2][i-1];
        
        else
            arr[j%2][i]=max(arr[j%2][i-1], arr[(j-1)%2][i]);
    }
    }
    return arr[n%2][m];
}
int main(){
    string s1="axyz", s2="baz";
    cout << lcs(s1, s2);

    return 0;
}