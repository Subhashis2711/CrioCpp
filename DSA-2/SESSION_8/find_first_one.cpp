#include <bits/stdc++.h>
using namespace std;

int zeroOnes(int n, vector<int > arr){
    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == 1 && (mid == 0 || arr[mid - 1] == 0)){
            return mid;
        }

        if(arr[mid] == 1){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return -1;
}


int main(){
    int n;
    cin>>n;
    vector<int > arr(n);
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    int result = zeroOnes(n, arr);
    cout << result << "\n";
}