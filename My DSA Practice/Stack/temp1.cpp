#include <bits/stdc++.h>
using namespace std;
stack<int> _push(int arr[],int n)
{
   stack<int> s;
   for (int i=0;i<n;i++){
    if (s.empty() || s.top()>=arr[i])
        s.push(arr[i]);
    else
        s.push(s.top());
   }
   return s;
}

void _getMinAtPop(stack<int>s)
{
    while(s.empty()==false){
        cout << s.top() << " ";
        s.pop();
    }
}
int main(){
    int arr[]={1 ,34 ,23 ,17, 37 ,42, 13 ,39, 0, 53 ,49, 6, 71};
    int n=sizeof(arr)/sizeof(int);
    stack<int> temp=_push(arr, n);
    _getMinAtPop(temp);
    return 0;
}