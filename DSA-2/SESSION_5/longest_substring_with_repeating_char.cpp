/*
Problem Description
Given a string, find the length of the longest substring which has no repeating characters.

Input format
Input is a string.

Output format
Output is an integer representing the longest substring with no repeating characters.

Sample Input 1
aabcccbcb

Sample Output 1
3
*/

#include <bits/stdc++.h>
using namespace std;

class LongestSubstringWithoutRepeatingCharacter {
public:
    // Function to find the longest substring length.
    int lengthOfLongestSubstring(string s) {
        // Initialise the longest substring length to 0.
        int longestSubstringLength = 0;
        unordered_set<int> st;
        int n = s.size();
        
        // Initialise start and end pointer to 0.
        int start = 0, end = 0;

        /*
        Iterate thorugh the window until start and end point to the 
        last address.
        */
        while(start < n && end < n){
            /* 
            If character at end pointer is not present in the set, 
            add the character to the set and move the end pointer 
            1 step forward. Keep track of the length (end - start) by
            comparing it with the max length(longestSubstringLength)
            Else, if present
            remove the character at the start and move the start
            pointer 1 step forward (Slide the window and repeating
            charcter are found in this window).
            */
            if(st.find(s[end]) == st.end()){
                st.insert(s[end]);
                end++;
                longestSubstringLength = max(longestSubstringLength, end-start);
            }else{
                st.erase(s[start]);
                start++;
            }
        }
        
        // Return the maximum length
        return longestSubstringLength;
    }
};

int main() {
    string s;
    getline(cin, s);
    int result =
        LongestSubstringWithoutRepeatingCharacter().lengthOfLongestSubstring(s);
    cout << result;
    return 0;
}