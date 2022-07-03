#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(int n, string s)
{
    unordered_map<char, int> counts;
    for(char c : s) counts[c]++;

    bool odd_found = false;
    int result = 0;

    for(auto& c : counts){
        if(c.second % 2 == 0){
            result += c.second;

        }else{
            odd_found = true;
            result += c.second - 1;
        }
    }

    if(odd_found){
        result += 1;
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = longestPalindrome(n, s);
    cout << ans << endl;
}