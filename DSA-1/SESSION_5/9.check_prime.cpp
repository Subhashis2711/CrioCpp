#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n == 2){
        return true;
    }

    if(n == 1){
        return false;
    }

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}
// TODO: Implement this method
vector<bool> checkPrime(int n, vector<int> nums){
    vector<bool> ans(n);
    bool prime;

    for(int j = 0; j < n; j++){
        ans[j] = isPrime(nums[j]);
        
    }
    
    return ans;
}

// NOTE: Please do not modify this function
int main(){
    int t,n;
    cin>>t;
    vector<int> nums;
    for( int i =0;i<t;i++){
        cin>>n;
        nums.push_back(n);
    }
    vector<bool> ans = checkPrime(t,nums);
    
    for(auto it: ans){
        if(it){
            cout<<"true\n";
        }
        else{
            cout<<"false\n";
        }
    }
}