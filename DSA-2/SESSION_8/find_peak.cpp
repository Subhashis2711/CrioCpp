#include <bits/stdc++.h>
using namespace std;

int findPeak(vector<int>&nums, int start, int end){
    if(start == end)
        return end;
    
    if(end == start + 1){
        if(nums[end] > nums[start])
            return end;
        return start;
    }

    while(start <= end){
        int mid = start + (end-start) / 2;

        if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
            return mid;
        } 

        if(nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1]){
            return findPeak(nums, start, mid - 1);
        }

        return findPeak(nums, mid+1, end);
    }

    return -1;
}

int peakElement(vector<int>&nums){
    int n = nums.size();

    return findPeak(nums, 0, n-1);
    
}

int main(){
    int N;
    cin>>N;
    vector<int>nums(N);
    for(auto &x:nums)cin>>x;
    cout<<peakElement(nums)<<"\n";
}