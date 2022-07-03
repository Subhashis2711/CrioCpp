#include <bits/stdc++.h>
using namespace std;

/*
Comaprator function for sorting logic. 
*/
bool cmp(int a, int b){
    return (abs(a) <= abs(b));
}

/*
Function to sort array based on absolute values.
*/
vector<int> sortArrayAbsolute(int n, vector<int>& nums){
    sort(nums.begin(), nums.end(), cmp);

    return nums;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> result = sortArrayAbsolute(n, nums);
    for (auto &&i : result)
    {
        cout << i << " ";
    }
}