#include <bits/stdc++.h>
using namespace std;
struct person{
    int age;
    float ht;
    person(int a, int h){
        age=a;
        ht=h;
    }
};
struct mycmp{
    bool operator()(person const &p1, person const &p2){
        return p1.ht>p2.ht;
    }
};
int main(){
    person p1(1,2), p2(2, 3), p3(3,4);
    person p[]={p3, p2, p1};
    priority_queue<person, vector<person>, mycmp> pq(p,p+3);
    for (auto i:p){
        cout << i.ht << " ";
    }
    return 0;
}