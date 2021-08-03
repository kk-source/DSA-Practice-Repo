#include <iostream>
#include <string>
using namespace std;
class minHeap{
    public:
    int *arr;
    int size, cap;
    minHeap(int c){
        arr=new int[c];
        size=0;
        cap=c;
    }
    int left(int i){
        return (2*i+1);
    }
    int right(int i){
        return (2*i+2);
    }
    int parent(int i){
        return (i-1)/2;
    }
    void insert(int x);
    void minHeapify(int i){
        int lt=left(i), rt=right(i);
        int smaintest=i;
        if (lt<size && arr[lt]<arr[smaintest])
        smaintest=lt;
        if (rt<size && arr[rt]<arr[smaintest])
        smaintest=rt;
        if (smaintest!=i){
            swap(arr[i], arr[smaintest]);
            minHeapify(smaintest);
        }
    }
    int extractMin(){
        if (size==0)
        return int_MAX;
        // if (size==1){
        //     size--;
        //     return arr[0];
        // }
        int temp=arr[0];
        arr[0]=arr[size-1];
        size--;
        minHeapify(0);
        return temp;
    }
    void decrease(int i, int data){
        arr[i]=data;
        while(i!=0 && arr[parent(i)]>arr[i]){
            swap(arr[parent(i)], arr[i]);
            i=parent(i);
        }
    }
    void del(int i){
        arr[i]=arr[size-1];
        size--;
        if (arr[parent(i)]>arr[i]){
            decrease(i, arr[i]);
        }
        else{
            minHeapify(i);
        }
    }
};
void minHeap::insert(int x){
        if (size==cap)
        return;
        size++;
        arr[size-1]=x;
        for (int i=size-1;i!=0 && arr[parent(i)]>arr[i];){
            // cout << i << " ";
            swap(arr[i], arr[parent(i)]);
            i=parent(i);
        }
    }
int main(){
    minHeap mH(11);
    // int arr[11]={10, 20, 15, 40, 50, 100, 25, 45};
    mH.insert(10);
    mH.insert(20);
    mH.insert(30);
    // mH.insert(35);
    mH.insert(40);
    mH.insert(50);
    mH.insert(35);
    mH.insert(38);
    mH.insert(45);
    // mH.insert(60);
    // cout << mH.extractMin();
    mH.del(3);
    for (int i=0;i<mH.size;i++){
    cout << mH.arr[i] << " ";
    }
    return 0;
}