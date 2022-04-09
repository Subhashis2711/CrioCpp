#include <bits/stdc++.h>
using namespace std;

class FirstMissingPositive {
  public:
    int firstMissingPositive(vector<int> nums) {
        int res = 0;
        unordered_set<int> s;

        for(int i=0; i< nums.size(); i++){
            if(nums[i] > 0){
                s.insert(nums[i]);
            }
        }

        int i = 1;
        while(true){
            if(s.find(i) != s.end()){
                ++i;
            }else{
                res = i;
                break;
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
