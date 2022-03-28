#include <bits/stdc++.h>
using namespace std;

// TODO: Implement this method
int factorial(int n){
    if(n == 1 || n == 0){
        return 1;

    }  

    return n * factorial(n-1);
}

// NOTE: Please do not modify this function
int main(){
    int n;
    cin >> n;
    int result = factorial(n);
    cout << result;
}