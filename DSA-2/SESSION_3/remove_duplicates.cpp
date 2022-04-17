#include <bits/stdc++.h>
using namespace std;

int removeDuplicatesFromSortedArrayII(int n, vector<int>& nums){
    int j = 0;

    for(int i = 0; i < n; i++){
        if(i < n-2 && nums[i] == nums[i+1] && nums[i] == nums[i+2]){
            continue;
        }else{
            nums[j++] = nums[i];
        }
    }

    for(int i = n-1; i >= j; i--){
        nums.pop_back();
    }

    return nums.size();

}


int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int new_length = removeDuplicatesFromSortedArrayII(n, nums);
    cout << new_length << "\n";
    for (int i = 0; i < new_length; i++)
    {
        cout << nums[i] << " ";
    }
}