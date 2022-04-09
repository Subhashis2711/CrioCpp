#include <bits/stdc++.h>
using namespace std;

vector<int> incrementNumber(int n, vector<int > A){
    // Reverse the array
    reverse(A.begin(), A.end());
    
    int carry = 1;
    int sum = 0;
    for(int i = 0; i < A.size(); i++){
        sum = A[i] + carry;
        A[i] = sum % 10;
        carry = sum / 10;
    }

    if(carry == 1){
        A.push_back(carry);
    }

    reverse(A.begin(), A.end());
    return A;
}


int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &i : A)
    {
        cin >> i;
    }
    vector<int> result = incrementNumber(n, A);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
}