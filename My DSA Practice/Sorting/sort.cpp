#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct point{int x, y;};
bool mycmp(point p1, point p2){
    return (p1.x < p2.x); // greater x values on RHS of array.
}
int main(){
    // int arr[]={10,20,5,7};
    // vector<int> arr={10,20,5,7};
    // int n=4;
    // sort(arr.begin(), arr.end());
    // for (int i:arr)
    // cout << i << " ";
    // cout << endl;
    // sort(arr.begin(), arr.end(), greater<int>());
    // for (int i:arr)
    // cout << i << " ";
    point arr[]={{3,10}, {2,8}, {5,4}};
    int n=3;
    sort(arr, arr+n, mycmp);
    for (auto i: arr)
    cout << i.x << " " << i.y << "\n";
    return 0;
}