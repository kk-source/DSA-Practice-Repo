#include <bits/stdc++.h>
using namespace std;

// Used for sorting by frequency. And if frequency is same,
// then by appearance
bool mycmp(pair<int, int> &a, pair<int, int> &b){
        if (a.second==b.second)
        return a.first<b.first;
        return a.second>b.second;
    }
    vector<int> sortByFreq(int arr[],int n)
    {
        vector<int> ans;
        unordered_map<int, int> m;
        vector<pair<int, int>> s;
        for (int i=0;i<n;i++)
        m[arr[i]]++;
        copy(m.begin(), m.end(), back_inserter(s));
        sort(s.begin(), s.end(), mycmp);
        for (auto i:s){
            while(i.second>0){
            ans.push_back(i.first);
            i.second--;
            }
        }
        return ans;
    }


// Driver program
int main()
{

int a[] = { 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8 };
int n = sizeof(a) / sizeof(a[0]);
vector<int>res;
res = sortByFreq(a, n);

for(int i = 0;i < res.size(); i++)
		cout<<res[i]<<" ";

return 0;

}
