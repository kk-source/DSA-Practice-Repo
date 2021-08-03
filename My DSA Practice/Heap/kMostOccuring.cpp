#include <bits/stdc++.h>
using namespace std;
struct mycmp 
    { 
        bool operator()(pair<int, int> p1, pair<int, int> p2) 
        {	 
            if (p1.second==p2.second){
                return p1.first<p2.first;
            }
        	return p1.second < p2.second;	 
        } 
    }; 
    int kMostFrequent(int arr[], int n, int k) 
    { 
    	unordered_map<int, int> mp;
    	for (int i=0;i<n;i++)
    	mp[arr[i]]++;
    	  
    	priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> pq(mp.begin(), mp.end());
    	int ans=0;
    	for (int i=0;i<k;i++){
            cout << pq.top().first << " ";
    	    ans+=pq.top().second;
    	    pq.pop();
    	}
    	return ans;
    }
int main(){
    int arr[]={3, 1,5,5,5,1,7,8};
    int n=sizeof(arr)/sizeof(int);
    kMostFrequent(arr,n,3);
    return 0;
}