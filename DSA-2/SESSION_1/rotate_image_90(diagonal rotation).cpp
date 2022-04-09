#include <bits/stdc++.h>
using namespace std;

class RotateImage {
  public:
    void rotateImage(vector<vector<int>>& arr,  int n) {
        // Rotate the matrix along the main diagonal
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
                
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                int temp = arr[i][j];
                arr[i][j] = arr[i][n-j-1];
                arr[i][n-j-1] = temp;
            }
        }

    }
};

int main() {
    int n;
    cin >> n;
    cout<<n;
    vector<vector<int>> matrix(n,vector<int> (n));    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
        cout<<"\n";
    }
    RotateImage().rotateImage(matrix, n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}