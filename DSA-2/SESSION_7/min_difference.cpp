#include <bits/stdc++.h>
using namespace std;

int minDiff(int n, vector<int> arr){
    sort(arr.begin(), arr.end());

    int diff = INT_MAX;

    for(int i = 0; i < arr.size()-1; i++){
        int dif = arr[i+1] - arr[i];

        diff = min(diff, dif);

    }

    return diff;
}

int main(){
    int n;
    cin>>n;
    vector<int > arr(n);
    for(auto &el: arr){
        cin>>el;
    }
    int ans = minDiff(n, arr);
    cout << ans << "\n";
}