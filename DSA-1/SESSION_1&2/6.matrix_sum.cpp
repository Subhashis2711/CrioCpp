#include <bits/stdc++.h>
using namespace std;

// TODO: Implement this method
vector<vector<int> > additionOfMatrix(vector<vector<int> > matrixOne,vector<vector<int> >matrixTwo, int n, int m) {
    vector<vector<int> > sum_matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum_matrix[i][j] = matrixOne[i][j] + matrixTwo[i][j];
        }
    }

    return sum_matrix;
}

// NOTE: Please do not modify this function
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > matrixOne(n, vector<int>(m));
    vector<vector<int> > matrixTwo(n, vector<int>(m));
    for(int i = 0 ; i < n  ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> matrixOne[i][j];
        }
    }
    for(int i = 0 ; i < n  ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> matrixTwo[i][j];
        }
    }
    vector<vector<int> > result = additionOfMatrix(matrixOne, matrixTwo, n, m);
    for(int i = 0 ; i < n  ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cout << result[i][j] <<" ";
        }
        cout << "\n";
    }
}

