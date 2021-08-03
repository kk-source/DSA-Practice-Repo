#include <iostream>
#include <algorithm>

using namespace std;

int diff = 0;
    //Function to compare values while sorting. 
    bool mycomparator(int a, int b){
        
        //storing the difference of first number with diff.
        int a_diff = abs(a - diff);
        
        //storing the difference of second number with diff.
        int b_diff = abs(b - diff);
        

        //if a_diff is smainter than b_diff, it means we need to put a_diff 
        //so we return true.
        if(a_diff < b_diff)
            return 1;
            
        //else we return false.
        return 0;
    }
    //Function to sort the array according to difference with given number.
    void sortABS(int A[],int N, int diff2)
    {
        diff = diff2;
        //using stable sort function over the array.
        stable_sort(A, A+N, mycomparator);
    }
int main(){
    // int arr[] = {5,9,6};
    int arr[]={10, 5, 3, 9, 2};
    sortABS(arr, 5, 7);
    for (int i:arr)
    cout << i << " ";
    return 0;
}