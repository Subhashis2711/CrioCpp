#include <bits/stdc++.h>
using namespace std;

class FirstMissingPositive {
  public:
    int firstMissingPositive(vector<int> nums) {
        int i, res = 0;

        sort(nums.begin(), nums.end());
        
        for(i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                if((nums[i+1] - nums[i]) > 1){
                    res = nums[i] + 1;
                    break;
                }
            }
        }

        if(res == 0){
            if(nums.size() > 0 && nums[i-1] > 0){
                res = nums[i-1] + 1;
            }else{
                res = 1;
            }
            
        }
        
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    int result = FirstMissingPositive().firstMissingPositive(nums);
    cout << result;
    return 0;
}
