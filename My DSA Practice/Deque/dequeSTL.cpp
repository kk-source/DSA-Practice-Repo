#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> dq={10,20,30};
    dq.push_front(5);
    dq.push_back(50);
    cout << dq[1] << endl;
    for (auto x:dq)
    cout << x << " ";
    cout << endl;
    //cout << dq.front() << " " << dq.back();
    auto it=dq.begin();
    it++;
    dq.insert(it, 15); // inserts before this iterator.
    dq.erase(it); // deletes element at it.
    cout << *it << endl;
    for (auto i:dq)
    cout << i << " ";
    dq.pop_front();
    dq.pop_back();
    //cout << " " << dq.size() << " ";
    return 0;
}