/*
Problem Description
Given an array of integers and a number k, find the maximum sum of a subarray of size k.

Input format
First line of input contains two integers N and K, where N is the size of the array and K is the subarray size.

Second line of input contains N integers denoting the array elements.

Output format
Print the maximum sum of a subarray of size k.

Sample Input 1
4 2

100 200 300 400

Sample Output 1
700
*/

#include <bits/stdc++.h>
using namespace std;

int maximumSubarraySumSizeK(vector<int>&arr, int n, int k){
    
}


int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<maximumSubarraySumSizeK(arr,n,k);
}