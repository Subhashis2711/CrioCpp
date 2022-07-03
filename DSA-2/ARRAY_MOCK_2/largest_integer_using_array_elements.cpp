/*
Problem Description
Given an array of non negative integers, arrange the elements, such that if made into a number, they form the largest number.

For instance,

Given the array [1, 3, 10] , this should be arranged to [3, 1, 10] - since the largest possible number formed by these numbers is 3110.

Input format
There are 2 lines of input

First-line contains n, the size of the array.

Next line contains n space-separated integers.

Output format
Print the largest number formed by arranging these numbers in the list.

Sample Input 1
2

10 2

Sample Output 1
210

Sample Input 2
5

3 30 34 5 9

Sample Output 2
9534330

Constraints
0<= n <=50000

0<= a[i] <= 10^4
*/


#include <bits/stdc++.h>
using namespace std;

class LargestNumber {
  public:

    // bool customCompare(int &a, int &b){
    //     string value1 = to_string(a) + to_string(b);
    //     string value2 = to_string(b) + to_string(a);
 
    //     return value1 > value2;
    // }
    struct {
        bool operator()(int a, int b) const
        {
            string value1 = to_string(a) + to_string(b);
            string value2 = to_string(b) + to_string(a);
    
            return value1 > value2;
        }
    } customCompare;

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), customCompare);
        string s;
        for (int &i: nums) {
            s += to_string(i);
        }
        return s;
      
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    string result = LargestNumber().largestNumber(nums);
    cout << result;
    return 0;
}



