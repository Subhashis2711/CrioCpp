/*
Problem Description
Given an array containing N integers and an integer K, Your task is to find the length of the longest subarray with the sum of the elements equal to the given value K.

Input format
The first line contains two integers N and K, denoting the size of the array and the sum to be formed respectively. The second line contains N elements, the elements of the array.

Output format
Return a single integer, the size of the longest subarray having sum K.

Sample Input 1
6 15

10 5 2 7 1 9

Sample Output 1
4

Explanation
The longest subarray is [5, 2, 7, 1].
*/

#include <bits/stdc++.h>
using namespace std;

int longestSubarrayHavingSumK(vector<int>&A, int K){
    int max_length = 0;
    vector<int> prefix;
    int n = A.size();
    int sum = 0;
    unordered_map<int,int> m;

    for(int i = 0; i < n; i++){
        sum += A[i];
        prefix.push_back(sum);
    }

    for(int i = 0; i < n; i++){
        if(prefix[i] == K){
            max_length = i + 1;
        
        }

        if(m.find(prefix[i]) == m.end()){
            m[prefix[i]] = i;
        }

        if(m.find(prefix[i] - K) != m.end()){
            if(max_length < (i - m[prefix[i] - K])){
                max_length = i - m[prefix[i] - K];
            }
        }

    }

    return max_length;
}


int main(){
    int N,K;
    cin>>N>>K;
    vector<int>A(N);
    for(auto &x:A)cin>>x;
    cout<<longestSubarrayHavingSumK(A,K)<<"\n";
}