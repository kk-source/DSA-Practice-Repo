#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(10);
    // q.push(100);
    q.pop();
    q.pop();
    // q.pop();
    // q.pop();
    cout << q.back() << " ";
    return 0;
}