#include <bits/stdc++.h>
using namespace std;

class SearchInRotatedSortedArray {
  public:

    int binarySearch(vector<int>& nums, int low, int high, int target){
        
        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target)
                return mid;
            
            if(target > nums[mid]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return -1;
    }

    int getPivot(vector<int>& nums, int low, int high){
        if(low >= high)
            return -1;
        
        if(low == high)
            return low;

        int mid = (low + high) / 2;
        
        if(mid <= high && nums[mid] > nums[mid+1])
            return mid;
        
        if(mid > 0 && nums[mid] < nums[mid-1])
            return mid-1;

        if(nums[0] > nums[mid])
            return getPivot(nums, low, mid-1);
        
        return getPivot(nums, mid+1, high);
    }

    int search(vector<int>& nums, int target) {
        // Your implementation goes here
        int n = nums.size();
        int pivot = getPivot(nums, 0, n-1);

        if(pivot == -1)
            return binarySearch(nums, 0, n-1, target);
        
        if(nums[pivot] == target)
            return pivot;
        
        if(nums[0] <= target)
            return binarySearch(nums, 0, pivot - 1, target);
        
        return binarySearch(nums, pivot + 1, n - 1, target);
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
    int queries;
    cin >> queries;
    for (int i = 0; i < queries; i++) {
        int target;
        cin >> target;
        int result = SearchInRotatedSortedArray().search(nums, target);
        cout << result << "\n";
    }

    return 0;
}