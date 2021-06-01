#include <iostream>
#include <string>
using namespace std;
#define MOD 1000000007
#define c 26
class Solution
{
    public:
    //Function to generate the list of factorials.
    void initializeFactorials(int totalLen, vector<int> &fact) 
    {
        long long int factorial = 1;
        fact.push_back(1); 
        for (int curIndex = 1; curIndex < totalLen; curIndex++)
        {
            factorial = (factorial * curIndex) % MOD;
            fact.push_back(factorial);
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
        initializeFactorials(S.length() + 1, fact);
        
        for (int i=0;i<n ;i++){
            // mul/=(n-i); // mul is a mod value ..  (res % x / (a )  != res / a ).. you cannnot divide them directly .. you have to use inverse modulus
            
            long long mul = fact[n - i - 1];
            
            int ind = S[i] - 'a';
            long long prev_count = (ind != 0 ? count[ind - 1] : 0) ;  // to cover 'a' too. 
            
            long long cur = prev_count*mul ; 
            ans=(ans+cur)%MOD;
            
    
            
            for (int j=(S[i]-'a');j<c;j++){
            
                count[j] --;
            }
        }
        return ans;
    }
};
int main(){
    

    return 0;
}