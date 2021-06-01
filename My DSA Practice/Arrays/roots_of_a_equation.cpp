#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

// void some(int a, int b, int c){
//     double i=sqrt(b*b-4*a*c);
//     cout << i << endl;

//     if (i<0){
//     cout << -1;
//     return;
//     }

//     long long ans1=(((-1)*b+i)/(2*a));
//     long long ans2=(((-1)*b-i)/(2*a));

//     cout << ans1 << " " << ans2; 
// }
// double termOfGP(int A,int B,int N)
//     {
//         if(N==1)
//         return A;
//         double res=A;
//         double r=(double)B/A;
//         for (int i=2;i<=N;i++){
//             res=res*r;
//             cout << res << " ";
//         }
//         return res;
//     }

// int exactly3Divisors(int N)
//     {
//         int res=0;
//         for (int i=2;i*i<=N;i++){
//             if (i==2 || i==3)
//                 res++;
//             if (i%2==0 || i%3==0)
//                 continue;
//             for (int j=5;j*j<=i;j+=6){
//                 if (i%j==0 || i%(j+2)==0)
//                 continue;
//             }
//                 res++;
//         }
//         return res;
//     }
// long long sumUnderModulo(long long a,long long b)
// {
//     return (a%1000000007+b%1000000007)%1000000007;
// }
void maximumAdjacent(int sizeOfArray, int arr[]){
    
    for (int i=0;i<sizeOfArray-1;i++){
        (arr[i]>arr[i+1])? cout << arr[i] << " " : cout << arr[i+1] << " ";
    }  
}
int maxOccured(int L[], int R[], int n, int maxx){
    
        vector<int> temp(maxx+1,0);
        for(int i=0;i<n;i++){
            temp[L[i]]++;
            temp[R[i]+1]--;
        }
        int res=0;
        int ind=0;
        for(int i=1;i<maxx+1;i++){
            temp[i]+=temp[i-1];
            if (res<temp[i]){
                res=temp[i];
                ind=i;
            }
        }
        return ind;
    }
void frequencycount(vector<int>& arr,int n)
    { 
        vector<int> temp(n+1,0);
        for (int i=0;i<n;i++){
            temp[arr[i]]++;
        }
        for (int i=1;i<=n;i++){
            arr[i-1]=temp[i];
            cout << arr[i-1] << " ";
        }
    }
int equilibriumPoint(long long arr[], int n) {
    
    //     for (int i=1;i<n;i++){
    //         a[i]+=a[i-1];
    //     }
    //     int last=a[n-1];
    //     for (int i=0;i<n;i++){
    //         if(i==0){
    //         if (last-a[i]==0){
    //             return a[i];
    //         }
    //         }
    //         else if (a[i-1]==last-a[i]){
    //             return a[i]-a[i-1];
    //         }
    // }
    //     return -1;
    long long arrsum=arr[0];
    for (int i=1;i<n;i++){
        arrsum+=arr[i];
    }
    long long lsum=0;
    for (int i=0;i<n;i++){
        if (lsum==arrsum-arr[i]){
            return arr[i];
        }
        lsum+=arr[i];
        arrsum-=arr[i];
    }
    return -1;
    }
int missingNumber(int arr[], int n) { 
        
        int counter=1;
        bool flag=true;
        while(flag){
            for (int i=0;i<n;i++){
                if (arr[i]==counter){
                    cout << "p" ;
                    counter++;
                    break;
                }
                if (i==n-1){
                flag=false;
                break;
                }
            }
        }
        return counter;
    }
int main(){
    int n = 5;
int L[] = {1,5,9,13,21};
int R[] = {15,8,12,20,30};
vector<int> temp={36, 20, 44, 5, 8, 2, 42, 36, 48, 5 ,7, 6, 20, 29 ,3, 43, 8 ,50, 28, 21, 3, 8 ,3 ,29 ,43 ,22 ,25 ,40 ,48, 46, 42, 10 ,24, 48, 36 ,35 ,44 ,4, 27, 46, 1, 13, 49 ,17 ,40, 2 ,42};
// cout << maxOccured(L,R,n,30);
frequencycount(temp,temp.size());

    // cout << termOfGP(84, 87, 6);
    // cout << exactly3Divisors(48);
    // cout << sumUnderModulo(8279685334796349382, 3890369874501826197);
    //int arr[] = {36, 20, 44, -5, 8, 2, -42, 36, 48, -45 ,-37, -6, -20, -29 ,-3, -43, 8 ,-50, 28, -21, -43, 8 ,3 ,29 ,-43 ,22 ,25 ,-40 ,-48, -46, -42, -10 ,-24, -48, 36 ,35 ,-44 ,-4, -27, -46, 1, -13, -49 ,-17 ,-40, -2 ,42};
    // maximumAdjacent(6,arr);
    // cout << missingNumber(arr,47);
     

    return 0;
}