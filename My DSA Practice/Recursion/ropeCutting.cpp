#include <iostream>
using namespace std;

int rope(int n, int a, int b, int c){
	if (n<0)
	return -1;
	if (n==0)
	return 0;
	int res=max(max(rope(n-a,a,b,c),rope(n-b,a,b,c)),rope(n-c,a,b,c));
	if(res==-1)
	return -1;
	return res+1;
}
int main() {
	cout << rope(5,1,2,5);
	return 0;
}