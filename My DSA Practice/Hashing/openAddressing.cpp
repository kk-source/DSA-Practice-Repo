#include <iostream>
#include <list>
using namespace std;
struct MyHash{
    int *arr;
    int cap, size;
    MyHash(int c){
        cap=c;
        size=0;
        arr=new int [c];
        for (int i=0;i<cap;i++)
            arr[i]=-1;
    }
    int hash(int key){
        return key%cap;
    }
    bool insert(int key){
        if (cap==size)
        return false;
        int i=hash(key);
        while(arr[i]!=-1 && arr[i]!=-2){
            if (arr[i]==key)
            return false;
            i=(i+1)%cap;
        }
        arr[i]=key;
        size++;
        return true;
    }
    bool search(int key){
        int h=hash(key);
        int i=h;
        while(arr[i]!=key){
            if (arr[i]==-1)
                return false;
            i=(i+1)%cap;
            if (i==h)
                return false;
        }
        return true;
    }
    bool erase(int key){
        int h=hash(key);
        int i=h;
        while(arr[i]!=key){
            if (arr[i]==-1)
            return false;
            i=(i+1)%cap;
            if (i==h)
            return false;
        }
        arr[i]=-2;
        size--;
        return true;
    }
};
int main(){
    MyHash mh(7);
    mh.insert(48);
    mh.insert(56);
    mh.insert(72);
    mh.erase(72);
    if (mh.search(72)==true)
        cout << "yes\n";
    else    
        cout << "no\n";
    // mh.erase(56);
    // if (mh.search(56)==true)
    //     cout << "yes\n";
    // else
    //     cout << "no\n";
    return 0;
}