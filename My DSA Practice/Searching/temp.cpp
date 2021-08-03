#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;


	int median(vector<vector<int>> &matrix, int r, int c)
    {
        int min = int_MAX, max = int_MIN;
        for (int i = 0; i < r; i++)
        {
            if (matrix[i][0] < min)
                min = matrix[i][0];
     
            if (matrix[i][c-1] > max)
                max = matrix[i][c-1];
        }
     
        int desired = (r * c + 1) / 2;
        int ans = min;
        while (min <= max)
        {
            // cout << min << " " << max << " ";
            cout << ans << " ";
            int mid = min + (max - min) / 2;
            int place = 0;
            for (int i = 0; i < r; ++i)
                place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if (place < desired){
                ans = min;
                min = mid + 1;
                
            }
            else
            {
                max = mid - 1;
            }
        }
        return min;
    }


int main()
{
	int r = 3, c = 5;
	// int m[][MAX]= { {5,9,20,30,40}, {1,2,3,4,6}, {11,13,15,17,19} };
    vector<vector<int>> ans={ {5,9,20,30,40}, {1,2,3,4,6}, {11,13,15,17,19} };
	// cout << "Median is " << matMed(m, r, c) << endl;
	cout << median(ans, r, c);
	return 0;
}
