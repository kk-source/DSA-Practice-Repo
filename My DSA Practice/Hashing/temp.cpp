#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--){
	    int b; cin >> b;
	    int temp=(b*b)/2-4;
        if (temp>0)
	    cout << temp/4 << endl;
        else 
        cout << 0 << endl;
	}
	return 0;
}
