#include <bits/stdc++.h>
using namespace std;

// TODO: Implement this method
bool checkMagicSquare(vector<vector<int> > mat, int n){
    int sumd1 = 0, sumd2 = 0;
    bool status = true;
    for(int i = 0; i < n; i++){
        sumd1 += mat[i][i];
        sumd2 += mat[i][n-1-i];
    }

    if(sumd1 != sumd2){
        status = false;
    }

    for(int i = 0; i < n; i++){
        int row_sum = 0, col_sum = 0;
        for(int j = 0; j< n; j++){
            row_sum += mat[i][j];
            col_sum += mat[j][i];
        }

        if(row_sum != col_sum || col_sum != sumd1){
            status = false;
        }
    }

    return status;
}

// NOTE: Please do not modify this function
int main(){
    int n;
    cin >> n;
    vector<vector<int> > mat(n, vector<int>(n));
    for(int i = 0 ; i < n  ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> mat[i][j];
        }
    }
    bool result = checkMagicSquare(mat, n);
    if(result) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}