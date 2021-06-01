#include<bits/stdc++.h>
using namespace std;
struct MyHash{
    int bucket;
    list <int> *ptr;
    MyHash(int b){
    bucket=b;
    ptr=new list <int> [b];
    }
    void insert(int key){
        int i=key%bucket;
        ptr[i].push_back(key);
    }
    void remove(int key){
        int i=key%bucket;
        ptr[i].remove(key);
    }
    bool search(int key);
    void keyvaluepair(int key, int val){
        ptr[key].push_back(val);
    }
};
bool MyHash :: search(int key){
        int i=key%bucket;
        for (auto i: ptr[i])
            if (i==key)
            return true;
        return false;
    }
int main(){
    MyHash mh(7);
	    mh.insert(10);
	    mh.insert(20);
	    mh.insert(15);
	    mh.insert(7);
	    cout << mh.search(10) << endl;
	    mh.remove(15);
        mh.keyvaluepair(1, 15);
	    cout << mh.search(15);
    return 0;
}