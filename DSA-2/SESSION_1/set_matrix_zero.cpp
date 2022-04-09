#include <bits/stdc++.h>
using namespace std;

class SetMatrixZeroes {
  public:

    void setMatrixZeroes(vector<vector<int>>& matrix, int m, int n) {
        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for(int i = 0; i < m; i++){
           for(int j = 0; j < n; j++){
               if(matrix[i][j] == 0){
                   row[i] = true;
                   col[j] = true;
               }
           }
       }

        for(int i = 0; i < m; i++){
           for(int j = 0; j < n; j++){
               if(row[i] || col[j]){
                   matrix[i][j] = 0;
               }
           }
       }
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m,vector<int> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
        cout<<"\n";
    }
    SetMatrixZeroes().setMatrixZeroes(grid, m, n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}