#include <iostream>
#include <string>
#include <queue>
using namespace std;
// no number contains 9.
void generate(int n){
    queue<string> q;
    q.push("1");
    q.push("2");
    q.push("3");
    q.push("4");
    q.push("5");
    q.push("6");
    q.push("7");
    q.push("8");
    for (int i=0;i<n;i++){
        string temp=q.front();
        cout << temp << " ";
        q.pop();
        q.push(temp+"0");
        q.push(temp+"1");
        q.push(temp+"2");
        q.push(temp+"3");
        q.push(temp+"4");
        q.push(temp+"5");
        q.push(temp+"6");
        q.push(temp+"7");
        q.push(temp+"8");
    }
}
int main(){
    generate(100);
    return 0;
}