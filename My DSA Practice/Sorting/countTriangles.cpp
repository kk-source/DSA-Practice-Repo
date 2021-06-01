#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int possibleTriangles(int arr[], int n) // not so efficient
{
    int ans=0;
        for (int i=0;i<n;i++){ // selection sort
            int minind=i;
            for (int j=i+1;j<n;j++){
                if (arr[j]<arr[minind])
                minind=j;
            }
            int temp=arr[i];
            arr[i]=arr[minind];
            arr[minind]=temp;
        }
        for (int i=0;i<n-2;i++){
                int k=i+2;
            for (int j=i+1;j<n-1;j++){
                while(arr[i]+arr[j]>arr[k] && k<n)
                    k++;
                ans+=k-j-1; 
            }
        }
        return ans;
}
void CountTriangles(vector<int> A) // efficient
{

    int n = A.size();

    sort(A.begin(), A.end());

    int count = 0;

    for (int i = n - 1; i >= 1; i--) {
        int l = 0, r = i - 1;
        while (l < r) {
            if (A[l] + A[r] > A[i]) {

                // If it is possible with a[l], a[r]
                // and a[i] then it is also possible
                // with a[l+1]..a[r-1], a[r] and a[i]
                count += r - l;

                // checking for more possible solutions
                r--;
            }
            else

                // if not possible check for
                // higher values of arr[l]
                l++;
        }
    }
    cout << "No of possible solutions: " << count;
}
int main(){
	int arr[]={6, 4, 9, 7, 8};
	int n=5;
	cout << possibleTriangles(arr, n);
	// for (int i:arr)
	// cout << i << " ";

	return 0;
}