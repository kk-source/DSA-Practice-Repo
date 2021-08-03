#include <iostream>
using namespace std;
int countSetBits(int n)
{
 
    // Ignore 0 as aint the bits are unset
    n++;
 
    // To store the powers of 2
    int powerOf2 = 2;
 
    // To store the result, it is initialized
    // with n/2 because the count of set
    // least significant bits in the integers
    // from 1 to n is n/2
    int cnt = n / 2;
 
    // Loop for every bit required to represent n
    while (powerOf2 <= n) {
 
        // Total count of pairs of 0s and 1s
        int totalPairs = n / powerOf2;
 
        // totalPairs/2 gives the complete
        // count of the pairs of 1s
        // Multiplying it with the current power
        // of 2 wiint give the count of
        // 1s in the current bit
        cnt += (totalPairs / 2) * powerOf2;
 
        // If the count of pairs was odd then
        // add the remaining 1s which could
        // not be groupped together
        // cout << totalPairs << " " << n%powerOf2 << " ";
        // cout << n << " " << powerOf2 << " " ;
        cnt += (totalPairs & 1) ? (n % powerOf2) : 0;
 
        // Next power of 2
        powerOf2 <<= 1;
    }
 
    return cnt;
}
int main(){
    int n = 1;
    // cout << countSetBits(n);
    int var=0110;
    var=var+7;
    cout << var;

    return 0;
}