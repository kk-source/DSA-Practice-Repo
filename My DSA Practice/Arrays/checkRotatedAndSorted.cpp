bool checkRotatedAndSorted(int arr[], int n){
        int minval=arr[0],maxval=arr[0];
        int minind=0,maxind=0;
        for (int i=1;i<n;i++){
           
            minval=min(arr[i],minval);
            if (minval==arr[i])
                minind=i;
            maxval=max(arr[i],maxval);
            if (maxval==arr[i])
                maxind=i;
        }
        if (abs(minind-maxind) !=  1 )
            return false;
        
        if (minind>maxind){
            int i=minind+1;
            do{
                if (arr[i%n]<=arr[(i-1)%n])
                return false;
                i++;
            }while(i%n!=maxind);
        }
        else if (minind<maxind){
            int i=maxind+1;
            do{
                if (arr[i%n] >= arr[(i - 1)%n])
                    return false;
                i++;
            }while(i%n != minind);
        }
        return true;
    }
int main(){
	int arr[]={30, 20, 10, 50, 35};
	int n=5;
    cout << checkRotatedAndSorted(arr,n);
	return 0;
}