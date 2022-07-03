#include <bits/stdc++.h>
using namespace std;

int numberOfOneBits(uint32_t n){
    unsigned int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}


int main(){
    unsigned n;
    cin>>n;

    int ans = numberOfOneBits(n);
    cout<<ans<<endl;
}