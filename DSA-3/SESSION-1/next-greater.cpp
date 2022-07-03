
#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement( vector<int>& A) {
    vector<int> result(A.size());

    stack<int> s;

    for(int i = 0; i < A.size(); i++){
        while(!s.empty() && A[i] > A[s.top()]){
            result[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()){
        result[s.top()] = -1;
        s.pop();
    }

    return result;


}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for ( int i = 0; i < n; i++) cin >> A[i];

    vector<int> next_larger = nextLargerElement(A);
    for ( int i = 0; i < n; i++) {
        if(next_larger[i] != -1){
            cout << A[next_larger[i]] << " "; 
        }else{
            cout << next_larger[i] << " ";
        }
    }
}