#include <bits/stdc++.h>
using namespace std;

// TODO: Implement this method
int findElementQuery(vector<int> vec, int n, int x){
    int lo = 0;
    int hi = n-1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;

        if(vec[mid] == x){
            return mid;
        }else if(vec[mid] > x){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }

    return -1;
}

// NOTE: Please do not modify this function
int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> vec[i];
    }
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        int result = findElementQuery(vec, n , x);
        cout << result << "\n";
    }
}