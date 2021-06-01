#include <iostream>
using namespace std;

void twoRepeated(int arr[], int N)
{
    int m = N - 1;
    for (int i = 0; i < N; i++) {
        arr[arr[i] % m - 1] += m;
        if ((arr[arr[i] % m - 1] / m) == 2)
            cout << arr[i] % m << " ";
    }
}
// Driver Code
int main()
{
    int arr[] = { 4, 2, 4, 5, 2, 3, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The two repeating elements are ";
  	twoRepeated(arr, n);

    return 0;
}
// This code is contributed by Kartik Singh Kushwah