#include <bits/stdc++.h>
using namespace std;

long long int maxSumTriplet(int n, vector<int> &nums){
    int ans = 0;
    for(int i = 1; i < n; i++){
        int max1 = 0, max2 = 0;
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                max1 = max(max1, nums[j]);
            }
        }

        for(int j = i+1; j < n; j++){
            if(nums[j] > nums[i]){
                max2 = max(max2, nums[j]);
            }
        }

        if(max1 && max2){
            ans = max(ans, (max1 + nums[i] + max2));
        }
    }

    return ans;
}

int main(){
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        long long int ans = maxSumTriplet(n, nums);
        cout << ans << endl;
    }
}
