#include <bits/stdc++.h>
using namespace std;

bool conditionFail(pair<int, int > &pos, vector<vector<int>> &matrix, int &n){
    int x = pos.first, y = pos.second;
    if(x >= n || x < 0 || y >= n || y < 0)
        return true;
    if (matrix[x][y] != 0)
        return true;
    return false;
}  

vector<vector<int > > spiralMatrixII(int n){
    vector<vector<int >> res(n, vector<int> (n, 0));
    int counter = 1;
    int top, bottom, left, right;
    top = left = 0;
    right = bottom = n-1;

    while(left <= right && top <= bottom){

        for(int i = left; i <= right; i++){
            res[top][i] = counter++;
        }
        ++top;

        for(int i = top; i <= bottom; i++){
            res[i][right] = counter++;
        }
        
        --right;

        for(int i = right; i >= left; i--){
            res[bottom][i] = counter++;
        }
        --bottom;

        for(int i = bottom; i >= top; i--){
            res[i][left] = counter++;
        }
        ++left;
    }

    return res;

}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > result = spiralMatrixII(n);
    for(auto &row: result){
        for(auto &element: row){
            cout<<element<<" ";
        }
        cout<<"\n";
    } 
}