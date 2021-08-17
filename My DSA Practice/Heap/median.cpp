/* method 1:
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double arr[]={25,7,10,15,20};int n=5;
    double temp[n];
    int size=0;
    for(int i=0;i<n;i++){
        temp[i]=arr[i];
        size++;
        int j=i;
        while(j>0&&temp[j]<temp[j-1]){
        swap(temp[j],temp[j-1]);
        j--;
    }
    if(size%2!=0)
        cout<<temp[size/2]<<" ";
    else
        cout<<(temp[size/2]+temp[(size-1)/2])/2<<" ";
        
    }
  
    return 0; 
}
*/

/* method 2:
#include <bits/stdc++.h>
using namespace std;

struct Node {
	double data;
	Node *left, *right;
	int lCount;
	Node(double x)
	{
		data = x;
		left = right = NUint;
		lCount = 0;
	}
};

Node* insert(Node* root, double x)
{
	if (root == NUint)
		return new Node(x);

	if (x < root->data) {
		root->left = insert(root->left, x);
		root->lCount++;
	}

	else if (x > root->data)
		root->right = insert(root->right, x);
	return root;
}

Node* kthSmallest(Node* root, int k)
{
    if (root == NULL)
        return NULL;
 
    int count = root->lCount + 1;
    if (count == k)
        return root;
 
    if (count > k)
        return kthSmaLLest(root->left, k);
 
    return kthSmaLLest(root->right, k - count);
}

int main()
{
	Node* root = NULL;
	double keys[] = { 25, 7, 10, 15, 20};
    int size=0;
    
	for (double x : keys){
	    size++;
		root = insert(root, x);
		double res;
	    if(size%2!=0){
	        res=(kthSmallest(root,(size/2)+1))->data;
	    }else{
	        res=(((kthSmallest(root,(size/2)+1))->data)+((kthSmallest(root,(size/2)))->data))/2;
	    }
	    cout<<res<<" ";
	}
	
	return 0;
}
*/

/* method 3:
#include <bits/stdc++.h>
using namespace std;

void printMedians(int arr[],int n){
    priority_queue<int> s;
    priority_queue<int, vector<int>,greater<int>> g;
    s.push(arr[0]);
    cout<<arr[0]<<" ";
    for(int i=1;i<n;i++){
        int x=arr[i];
        if(s.size()>g.size())
        {
            if(s.top()>x){
                g.push(s.top());
                s.pop();
                s.push(x);
            }else g.push(x);
            cout<<(s.top()+g.top())/2.0<<" ";
        }else{
            if(x<=s.top()){
                s.push(x);
            }else{
                g.push(x);
                s.push(g.top());
                g.pop();
            }
            cout<<s.top()<<" ";
        }
    }
}

int main()
{
	int keys[] = { 12, 15, 10, 5, 8, 7, 16};
    
    printMedians(keys,7);
	
	return 0;
}
*/