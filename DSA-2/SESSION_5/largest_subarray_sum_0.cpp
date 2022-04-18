/*
Problem Description
Given an integer array, find the largest subarray with sum 0 . If there is more than one subarray with the largest length, return the subarray with the lowest starting index.

If there is no such sub-array print -1.

Input format
There are 2 lines of input.

First line contains an integer N.

Next line consists of N integers, the values of the array.

Output format
Print the elements of the sub-array with spaces which have the largest length and sum of elements equal to zero.

Sample Input 1
6

2 3 1 -4 0 6

Sample Output 1
3 1 -4 0
*/

// Solution using Prefix-sum and Sliding-Window.
#include <bits/stdc++.h>
using namespace std;

// Function to find the longest subarray having sum = 0
vector<int> largestSubarraySumZero(int n, vector<int> arr){
    // Initialise the res vector for storing the result(sub array)
    vector<int> res;

    // Initialise the prefix vector for storing prefix sum
    vector<int> prefix;

    // Initialise an unordered map with prefix sum as key and index as value.
    unordered_map<int, int> m;

    // Create a prefix-sum vector
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        prefix.push_back(sum);
    }

    // Store prefix-sum 0 as key with value = -1.
    m[0] = -1;

    // Initialise max_length to 0.
    int max_length = 0;

    // Initialise start and end pointers to 0.
    int start = 0, end = 0; 

    // Iterate over the prefix sum array.
    for(int i = 0; i < n; i++){
        /*
        Check whether a prefix sum is repeating by checking the map keys.
        If repeating calculate the length between the stored index(map value)
        and the current index.
        */
         if(m.find(prefix[i]) != m.end()){
            int length = i - m[prefix[i]];
            
            /*
            As we have to find the subarray with lowest index, so we have to check 
            if calculated length > max_length(not equal).
            If true, update the max_length and update the end pointer to current
            index and start pointer to (i - max_length + 1).
            Else update the map with the prefix sum at current index as value 
            and index as key. 
            */
            if(length > max_length){
                max_length = max(length, max_length);
                end = i;
                start = i - max_length + 1;
            }
        }else{
            m[prefix[i]] = i;
        }
    }

    /*
    If start and end are still at 0 and max_length is equal to 0, then push -1 
    as subarray to the result.
    Else iterate the original array from start till end and push the values to 
    the result.
    */
    if(start == 0 && end == 0 && max_length == 0){
        res.push_back(-1);
    }else{
        for(int i = start; i <= end; i++){
            res.push_back(arr[i]);
        }
    }

    // Return result containing the subarray.
    return res;
}


int main(){
    
    int n;
    cin>>n;

    vector<int> arr(n);
    for(auto &i:arr) {
        cin>>i;
    }

    vector<int> longestSubarray = largestSubarraySumZero(n, arr);
    
    for(auto i:longestSubarray) {
        cout<<i<<" ";
    }
}