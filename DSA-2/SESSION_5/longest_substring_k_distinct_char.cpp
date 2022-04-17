#include<bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char,int> m;
    int l = 0;
    int result = 0;

    for(int i = 0; i < s.size(); i++){
        if(m.find(s[i]) != m.end()){
            m[s[i]]++;
        }else{
            m[s[i]] = 1;
        }

        if(m.size() <= k){
            result = max(i-l+1, result);
        }else{
            if(m[s[l]] == 1){
                m.erase(s[l]);
            }else{
                m[s[l]]--;
            }
            l++;

        }

    }

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