#include <bits/stdc++.h>
using namespace std;

long long int power(long long int x, long long int n){
    long long int extra = 1;
    // cout<<x<<endl;


    if(n % 2 == 0){
        while(n > 1){
            x = x * x;
            n = n / 2;
        }
    }else{
        while(n > 1){
            if(n % 2 != 0){
                n = (n - 1);
                extra = extra * x;
            }else{
                n = n / 2;
                x = x * x;

            }

        }
    }

    long long int res = x * extra;


    return res;
}

long long int  BinarySearch(long long int low, long long int high, long long int n){
    long long int x = high;
    long long int result = 0;

    while(low <= high){
        long long int mid = low + (high-low) / 2;

        if(pow(mid, n) == x)
            return mid;
        
        if(pow(mid, n) <= x){
            result = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return result;
}


long long int nthRoot(long long int x, long long int n){
    long long int result;

    if(x >= 0 && x <= 1){
        result = BinarySearch(x, 1, n);
    }else{
        result = BinarySearch(1, x, n);
    }

    return result;

}


int main(){
    int t;
    cin>>t;

    while(t--) {
        long long int x, n;
        cin>>x>>n;

        long long int ans = nthRoot(x, n);
        cout<<ans<<endl;
    }
}