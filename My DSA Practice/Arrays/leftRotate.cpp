#include <iostream>
#include <string>
using namespace std;
void Lrotate(int arr[], int n)
{
    int temp = arr[0];
    int i;
    for (i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[i] = temp;
}
int main()
{
    int arr[] = {1, 0, 4, 0, 0, 45, 0, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    Lrotate(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}