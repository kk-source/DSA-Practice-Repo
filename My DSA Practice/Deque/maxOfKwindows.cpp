#include<iostream>
#include<deque>
using namespace std;
// naive O(nk).
void count(int arr[], int n, int k)
{
for (int i=0;i<=n-k;i++){
int maxval=arr[i];
for (int j=1;j<k;j++){
maxval=max(maxval, arr[i+j]);
}
cout << maxval << " ";
}
}

// O(n).
void count1(int *arr, int n, int k)
    {
        vector<int> ans;
        deque<int> dq;
        for (int i=0;i<k;i++){
            while(dq.empty()==false && arr[dq.back()]<=arr[i])
            dq.pop_back();
            dq.push_back(i);
        }
        cout << arr[dq.front()] << " ";
        for (int i=k;i<n;i++){
            if (dq.empty()==false && dq.front()<=i-k)
            dq.pop_front();
            while(dq.empty()==false && arr[dq.back()]<=arr[i])
            dq.pop_back();
            dq.push_back(i);
            cout << arr[dq.front()] << " ";
        }
    }

int main()
{
    int arr[]={10,20,5,8,8,6,15};
    //int arr[]={10, 8, 5, 12, 15, 7, 6};
    int n=sizeof(arr)/sizeof(int);
    count(arr, n, 3);
    cout << endl;
    count1(arr, n, 3);
    return 0;
}