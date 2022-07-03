/*
Problem Description
Given an array *nums*, find all unique triplets (group of 3 numbers) such that their sum is 0. There should be no duplicates i.e. no triplet should be repeated.

Input format
The first line consists of an integer, N, denoting the size of the array.

The second line consists of N space separated integers which denote the elements of the array, nums.

Output format
You must return all such unique triplets which sum to 0 from the given array.

Constraints
0 <= N <= 10^3

0 <= | nums[i] | <= 10^6, where nums[i] represents the value of each element in the array

Sample Input 1
6

-1 0 1 2 -1 -4

Sample Output 1
-1 0 1

-1 -1 2

Explanation 1
These 2 triplets sum to 0 and there are no other such unique combinations. Note that the combination [-1 , 0, 1] can be created twice but is not repeated since we are only displaying unique combinations.
*/
#include <bits/stdc++.h>
using namespace std;


class ThreeSum {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > answer;
        
        int i;
        sort(nums.begin(), nums.end());
        int n = nums.size();

	    for (i = 0; i < n - 2; i++){
            if (i == 0 || nums[i] > nums[i - 1]){
               
                int start = i + 1;
                int end = n - 1;
                int target = 0 - nums[i];

                while (start < end){
                    
                    if (start > i + 1 && nums[start] == nums[start - 1]){
                        start++;
                        continue;
                    }

                   
                    if (end < n - 1 && nums[end] == nums[end + 1]){
                        end--;
                        continue;
                    }

                    
                    if (target == nums[start] + nums[end]){   
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[start]);
                        v.push_back(nums[end]);

                        answer.push_back(v);
                        start++;
                        end--;
                    }else if (target > (nums[start] + nums[end])){
                        start++;
                    }else {
                        end--;
                    }
                }
            }
        }

        return answer;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }

    vector<vector<int>> result = ThreeSum().threeSum(nums);
    for (unsigned int i = 0; i < result.size(); i++) {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2];
        cout << endl;
    }
    return 0;
}