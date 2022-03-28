#include <bits/stdc++.h>
using namespace std;

// TODO: Implement this method
int nthFibonacciNumber(int n){
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    
    return nthFibonacciNumber(n-1) + nthFibonacciNumber(n-2);
}

// NOTE: Please do not modify this function
int main(){
    int n;
    cin >> n;
    int result = nthFibonacciNumber(n);
    cout<<result;
}