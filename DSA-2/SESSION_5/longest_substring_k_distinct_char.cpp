/*
Problem Description
Given a string, find the length of the longest substring that contains at most K distinct characters.

Note:

Uppercase and Lowercase characters should be considered as different characters.

There can be numbers and special characters as well.

Input format
There are 2 lines of input.

First-line contains two space-separated integers representing the value of N and K.

The next line contains the string S of length N.

Output format
The length of the longest substring T that contains at most K distinct characters.

Constraints
1 <= N <= 10^5

0 <= K <= 256

Sample Input 1
5 3

abacd

Sample Output 1
4
*/

// Solution using Variable Length Sliding Window technique
#include<bits/stdc++.h>
using namespace std;

/* 
Function to find the longest substring length with k 
distinct character 
*/
int lengthOfLongestSubstringKDistinct(string s, int k) {
    /* 
    Create an unordered map to store the frequency as values and
    character of the string as keys.
    */ 
    unordered_map<char,int> m;
    
    int result = 0;       // Initialise result(maxlength) to 0
    int l = 0;            // Initialise left pointer to 0

    
    // Iterate the right pointer from 0 upto size
    for(int i = 0; i < s.size(); i++){
        /* 
        Store/Update the frequency of the current character in the
        map.
        */
        if(m.find(s[i]) != m.end()){
            m[s[i]]++;
        }else{
            m[s[i]] = 1;
        }

        /*
        Check, If the size of the map is less than or equal to k
        Calculate the maximum between result and 
        window length(i-l+1).
        */
        if(m.size() <= k){
            result = max(i-l+1, result);
        }else{
            /*
            Else, decrease the frequency of the character at 
            i(if present).If freqency is 1, remove character from the 
            map. Move the left pointer(l) one step forward.
            */
            if(m[s[l]] == 1){
                m.erase(s[l]);
            }else{
                m[s[l]]--;
            }
            l++;

        }

    }

    // Return the max length 
    return result;
}

int main() {
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	int answer = lengthOfLongestSubstringKDistinct(s,k);
	cout <<  answer;
	return 0;
}