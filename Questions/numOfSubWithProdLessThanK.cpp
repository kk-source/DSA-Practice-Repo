#include <bits/stdc++.h>
using namespace std;
/*naive
int fun(int arr[], int k, int n, long long mul=1){
        if (mul>k)
        return 0;
        if (n==0){
            // cout << mul << ' ';
        return 1;
        }
        
        return fun(arr, k, n-1, mul*arr[n-1])+fun(arr, k, n-1, mul);
    }
int numOfSubsets(int arr[], int N, int K) {
    return fun(arr, K, N)-1;
}
*/
int numOfSubsets(int arr[], int n, int k) {
        
        // declare four vector for dividing array into  
        // two halves and storing product value of   
        // possible subsets for them 
        vector<int> vect1, vect2, subset1, subset2; 
      
        // ignore element greater than k and divide 
        // array into 2 halves 
        for (int i = 0; i < n; i++) { 
      
            // ignore element if greater than k 
            if (arr[i] > k) 
                continue; 
            if (i <= n / 2) 
                vect1.push_back(arr[i]); 
            else
                vect2.push_back(arr[i]); 
        } 
      
        // generate all subsets for 1st half (vect1) 
        for (int i = 0; i < (1 << vect1.size()); i++) { 
            int value = 1; 
            for (int j = 0; j < vect1.size(); j++) { 
                if (i & (1 << j)) 
                    value *= vect1[j]; 
                if (value > k)
                    break;
            } 
      
            // push only in case subset product is less  
            // than equal to k 
            if (value <= k) 
                subset1.push_back(value); 
        } 
      
        // generate all subsets for 2nd half (vect2) 
        for (int i = 0; i < (1 << vect2.size()); i++) { 
            int value = 1; 
            for (int j = 0; j < vect2.size(); j++) { 
                if (i & (1 << j)) 
                    value *= vect2[j]; 
                if (value > k)
                    break;
            } 
      
            // push only in case subset product is 
            // less than equal to k 
            if (value <= k) 
                subset2.push_back(value); 
        } 
        for (auto i:subset1)
            cout << i << " ";
        cout << endl;
        for (auto i:subset2)
            cout << i << ' ';
        // sort subset2 
        sort(subset2.begin(), subset2.end()); 
      
        int count = 0; 
        for (int i = 0; i < subset1.size(); i++) 
            count += upper_bound(subset2.begin(), subset2.end(),  
                             (k / subset1[i])) - subset2.begin(); 
      
        // for null subset decrement the value of count 
        count--; 
      
        // return count 
        return count; 
    }
int main(){
    int arr[]={2, 4, 5, 3};
    int n=4;
    numOfSubsets(arr, n, 12);    

    return 0;
}