#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}
// TODO: Implement this method
int coprimeNumbers(int n){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(gcd(n,i) == 1){
            count += 1;
        }
    }

    return count;
}



// NOTE: Please do not modify this function
int main(){
    int n;
    cin >> n;
    int result = coprimeNumbers(n);
    cout << result;
}