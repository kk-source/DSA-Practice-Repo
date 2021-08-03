#include <bits/stdc++.h>
using namespace std;

bool mycmp(pair<float, int> p1, pair<float,int> p2){
double r=(double)p1.second/p1.first;
double s=(double)p2.second/p2.first;
return r>s;
}

double fun(vector<pair<int, int>> &arr, int cap){
    int n=arr.size();
    sort(arr.begin(), arr.end(), mycmp);
    double ans=0.0;
    for (int i=0;i<n;i++){
        if (cap>arr[i].first){
            cap-=arr[i].first;
            ans+=arr[i].second;
        }
        else{
            ans+=((double)arr[i].second/arr[i].first)*cap;
            break;
        }
    }
    return ans;
}
int main(){
    int n=70;
    vector<pair<int, int>> temp={{50, 600}, {20, 500}, {30, 400}};
    cout << fun(temp, n);
    return 0;
}