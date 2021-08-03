#include <bits/stdc++.h>
using namespace std;
// set for user defined data type.
struct test{
    int x;
    bool operator < (test &t)
    {
        return this->x < t.x;
        // return x<t.x;
    }
};
int main(){
    set<test> s;
    s.insert({5});
    s.insert({20});
    s.insert({10});
    for (test t:s)
    cout << t.x << " ";
    return 0;
}