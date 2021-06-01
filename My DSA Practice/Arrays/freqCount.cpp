#include <iostream>
using namespace std;
void frequencycount(int* arr,int n)
    { 
        for (int i=0;i<n;i++){
            arr[arr[i]%(n+1)-1]+=n;
        }
        for (int i=0;i<n;i++){
            cout << arr[i] << " ";
            arr[i]=arr[i]/n;
            cout << arr[i] << " ";
        }
    }
void findCounts(int *arr, int n)
{
    // Traverse all array elements
    int i = 0;
    while (i<n)
    {
        // If this element is already processed,
        // then nothing to do
        if (arr[i] <= 0)
        {
            i++;
            continue;
        }

        // Find index corresponding to this element
        // For example, index for 5 is 4
        int elementIndex = arr[i]-1;

        // If the elementIndex has an element that is not
        // processed yet, then first store that element
        // to arr[i] so that we don't lose anything.
        if (arr[elementIndex] > 0)
        {
            arr[i] = arr[elementIndex];

            // After storing arr[elementIndex], change it
            // to store initial count of 'arr[i]'
            arr[elementIndex] = -1;
        }
        else
        {
            // If this is NOT first occurrence of arr[i],
            // then decrement its count.
            arr[elementIndex]--;

            // And initialize arr[i] as 0 means the element
            // 'i+1' is not seen so far
            arr[i] = 0;
            i++;
        }
    }  

    printf("\nBelow are counts of all elements\n");
    for (int i=0; i<n; i++)
        printf("%d -> %d\n", i+1, abs(arr[i]));
}
int main(){
    int arr[]={2,3,2,3,5};
	int n=5;
    findCounts(arr,n);
    // frequencycount(arr,n);
    return 0;
}