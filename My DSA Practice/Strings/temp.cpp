// another method of doing lexicographic question.
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define c 26
//Function to generate the list of factorials.
    void initializeFactorials(int totallen, vector<int> &fact) 
    {
        long long int factorial = 1;
        fact.push_back(1); 
        for (int curIndex = 1; curIndex < totallen; curIndex++)
        {
            factorial = ((factorial% MOD) * (curIndex% MOD)) % MOD;
            fact.push_back(factorial);
        }
        vector<int>:: iterator i=fact.begin();
        while(i!=fact.end()){
        cout << *i << " ";
        i++;
        }
        return;
    }
  
    
    //Function to find lexicographic rank of a string.
      int findRank(string S) 
    {
        int n=S.size();
        int count[c]={0};
        // long long mul=1;
        // for (int i=n;i>=1;i--)
        //     mul=(mul*i)%1000000007;
        for (int i=0;i<n;i++){
            count[S[i]-'a']++;
            if (count[S[i]-'a']>1)
                return 0;
        }
        for (int i=1;i<c;i++){
            count[i]+=count[i-1];      
        }
        long long ans=1;        
        
           vector<int> fact;
        initializeFactorials(n+1, fact);
        
        for (int i=0;i<n-1 ;i++){
            // mul/=(n-i); // mul is a mod value ..  (res % x / (a )  != res / a ).. you cannnot divide them directly .. you have to use inverse modulus
            
            long long mul = fact[n - i - 1];
            // cout << mul << " ";
            int ind = S[i] - 'a';
            long long prev_count = (ind != 0 ? count[ind - 1] : 0) ;  // to cover 'a' too. 
            
            long long cur = (prev_count*mul) ; 
            ans=((ans%MOD)+(cur%MOD))%MOD;
            
    
            
            for (int j=(S[i]-'a');j<c;j++){
            
                count[j] --;
            }
        }
        return ans;
    }
int main(){
    string str="abcdefghijklmnopqrstuvwxyz";
    // string str="string";
    cout << findRank(str);

    return 0;
}