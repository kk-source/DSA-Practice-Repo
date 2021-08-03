#include <iostream>
#include <string>
using namespace std;
void fun(int k, string str, string &ans)
    {
        if (k==0)
            return;
        
        int n=str.size();
        // i always begins from 0 because we don't know char at first position is final or not.(as in optimised approach).
        for (int i=0;i<n-1;i++) // can bind i into function parameters but will lead to extra overhead.
        {
            for (int j=i+1;j<n;j++)
            {
                if (str[i]<str[j])
                {
                    swap(str[i], str[j]);
                    if (str>ans)
                    ans=str;
                    fun(k-1, str, ans);
                    swap(str[i], str[j]);
                }
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       string ans=str;
       fun(k, str, ans);
       return ans;
    }
// Better.
/*
void fun(int start, int k, string str, string &ans)
    {
        if (k==0)
        {
            return;
        }
        
        int n=str.size();
        char maxc=str[start];
        for (int i=start+1;i<n;i++)
        {
            if (str[i]>maxc)
                maxc=str[i];
        }
        if (maxc!=str[start])
            k--;
        for (int i=start;i<n;i++)
        {
            if (str[i]==maxc)
            {
                swap(str[i], str[start]);
                if (str>ans)
                    ans=str;
                fun(start+1, k, str, ans);
                swap(str[i], str[start]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       string ans=str;
       fun(0, k, str, ans);
       return ans;
    }
*/
int main(){
    string str="54324";
    cout << findMaximumNum(str, 3);
    return 0;
}