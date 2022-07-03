#include <bits/stdc++.h>
using namespace std;


int BinarySearch(vector<int> arr, int low, int high, int m_mid){
    int res = 0;
    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] <= m_mid){
            res =  mid + 1;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return res;
}

int lessThanEqual(vector<vector<int>> matrix, int mid){
    int n = matrix.size();

    int cnt = 0;

    for(int i = 0; i < n; i++){
        int x = BinarySearch(matrix[i], 0, n-1, mid);
        cnt += x;
    }

    return cnt;
}

int kthSmallestElementInMatrix(vector<vector<int>> matrix,int k)
{
    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n-1][n-1];
    int ans = 0;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(lessThanEqual(matrix, mid) >= k){
            ans = mid;
            high = mid - 1;
    
        }else{
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n,k;cin>>n>>k;

    vector<vector<int> > matrix(n);
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            int x;cin>>x;
            matrix[i].push_back(x);
        }
    }
    int ans = kthSmallestElementInMatrix(matrix,k);
    cout<<ans<<endl;
}