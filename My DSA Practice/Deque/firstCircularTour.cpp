#include <bits/stdc++.h>
using namespace std;
// O(n^2).
int petrol(vector<pair<int, int>> arr, int n)
{
    for (int i=0;i<n;i++){
        int count=0;
        int j=i;
        while (true){
            count+=arr[j].first-arr[j].second;
            if (count<0)
            break;
            j=(j+1)%n;
            if (j==i)
            return i+1;
        }
    }
    return -1;
}
int petrol1(vector<pair<int, int>> arr, int n)
{
    deque<int> dq;
    int count=0;
    int i=0;
    bool flag=false;
    while(true){
        // if we reach starting point.
        if (i==dq.front())
        return i+1;

        count+=arr[i].first-arr[i].second;
        dq.push_back(i);

        // if we take 0 as starting point once again.
        if (dq.front()==0 && flag==true)
        return -1;

        // while count<0 remove front elements.
        while(dq.empty()==false && count<0){
        flag=true;
        count-=arr[dq.front()].first-arr[dq.front()].second;
        dq.pop_front();
        }
        i=(i+1)%n;
        }
}
// 2n traversals in worst case.
int petrol2(vector<pair<int, int>> arr, int n)
{
    int start=0, end=0;
    int rem=0;
    while(true){
        rem+=arr[end].first-arr[end].second;
        if (rem<0){
            end=(end+1)%n;
            start=end;
            rem=0;
            if (start==0)
            return -1;
        }
        end++;
        if (end==start)
        return start+1;
    }
}
// one traversal.
int petrol3(vector<pair<int, int>> arr, int n) // optimised of above approach.
{
    int start=0;
    int rem=0, prem=0;
    for (int i=0;i<n;i++){
        rem+=arr[i].first-arr[i].second;
        if (rem<0){
            start=i+1; // if i=n-1 then ans will be -1.
            prem+=rem;
            rem=0;
            cout << start << endl;
        }
    }
    return (prem+rem>=0)? start+1:-1;
}
int main(){
    vector<pair<int, int>> v={{11,10}, {12,11}, {13,12}, {6,10}};
    int n=v.size();
    cout << petrol3(v, n);

    return 0;
}