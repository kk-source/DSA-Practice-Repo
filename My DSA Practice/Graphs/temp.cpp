#include <bits/stdc++.h>
using namespace std;
int minSwaps(vector<int>&arr) // O(n^2).
	{
	    int n=arr.size();
	    int ans=0;
	    for (int i=0;i<n;i++){
	        int item=arr[i];
	        int pos;
	        do{
	            pos=i;
	        for (int j=i+1;j<n;j++){
	            if (arr[j]<item)
	            pos++;
	        }
	        swap(item, arr[pos]);
            if (pos!=i)
	        ans++;} while(pos!=i);
	        
	    }
	    return ans;
	}
	int minSwaps1(vector<int>&arr) // O(nlogn).
	{
	    int n=arr.size();
	    vector<pair<int, int>> temp;
	    for (int i=0;i<n;i++){
	        temp.push_back({arr[i], i});
	    }
	    sort(temp.begin(), temp.end());
	   // int bool[n];
	   int ans=0;
	   bool vis[n];
	   for (int i=0;i<n;i++)
	   vis[i]=false;
	   for (int i=0;i<n;i++){
	       if (vis[i] || temp[i].second==i)
	       continue;
	       else{
	           int j=i;
	           int c=0;
	           while(vis[j]!=true){
	               vis[j]=true;
	               c++;
	               j=temp[j].second;
	           }
	           if (c>1)
	           ans+=c-1;
	       }
	   }
	   return ans;
	}
int main(){
    vector<int> arr={4,2,3,1};
    cout << minSwaps(arr);
    return 0;
}