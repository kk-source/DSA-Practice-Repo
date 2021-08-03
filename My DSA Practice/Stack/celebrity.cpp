#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int> >& M, int n) 
    { // naive. O(n^2) n*2n.
        for (int i=0;i<n;i++){
            int j;
            for (j=0;j<n;j++){
                if (M[i][j]==1)
                break;
            }
            if (j==n){
                for (j=0;j<n;j++){
                    if (j==i && M[j][i]==1){
                    break;
                    }
                    else if (M[j][i]==0 && i!=j){
                    break;
                    }
                }
            if (j==n)
            return i;
            }
        }
        return -1;
    }
int celebrity1(vector<vector<int> >& M, int n) 
    { // optimised.
        int i=0, j=n-1;
        while(i<j){
            if (M[i][j]==1)
            i++;
            else
            j--;
        }
        int fix=i;
        for (int i=0;i<n;i++){
            if (M[fix][i]==1)
            return -1;
            if (M[i][fix]==0 && i!=fix)
            return -1;
        }
        return fix;
    }
int main(){
    vector<vector<int>> arr={{0, 0, 0},
                            {0, 0, 0}, 
                            {0, 0, 0}};
    cout << celebrity1(arr, 3);

    return 0;
}
/*
#define N 8
  
// Person with 2 is celebrity
bool MATRIX[N][N] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};
  
bool knows(int a, int b)
{
    return MATRIX[a][b];
}
  
// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n)
{
    // Handle trivial 
    // case of size = 2
    stack<int> s;
  
    // Celebrity
    int C; 
  
    // Push everybody to stack
    for (int i = 0; i < n; i++)
        s.push(i);
  
    // Extract top 2
   
  
    // Find a potential celebrity
    while (s.size() > 1)
    {   int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (knows(A, B))
        {
          s.push(B);
        }
        else
        {
          s.push(A);
        }
    }
    // If there are only two people 
    // and there is no
    // potential candicate
    if(s.empty())
        return -1;
    
    
    // Potential candidate?
    C = s.top();
    s.pop();
  
    // Check if C is actuainty
    // a celebrity or not
    for (int i = 0; i < n; i++)
    {
        // If any person doesn't 
        // know 'C' or 'C' doesn't 
        // know any person, return -1
        if ( (i != C) &&
                (knows(C, i) || 
                 !knows(i, C)) )
            return -1;
    }
  
    return C;
}
*/