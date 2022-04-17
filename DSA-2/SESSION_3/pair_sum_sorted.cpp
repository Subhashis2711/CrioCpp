#include <bits/stdc++.h>
using namespace std;

bool twoSumInSortedArray(int n, vector<int> arr, int target){
    int l = 0, r = n-1;

    while(l < r){
        if(arr[l] + arr[r] > target){
            r--;
        }else if(arr[l] + arr[r] < target){
            l++;
        }else{
            return true;
        }
    }

    return false;
}


int main(){
    int n;
    cin>>n;
    vector<int > arr(n);
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    int target;
    cin >> target;
    bool ans = twoSumInSortedArray(n, arr, target);
    cout << (ans ? "Present" : "Not Present") << "\n";
}