#include <bits/stdc++.h>

using namespace std;

class LongestCommonPrefix {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i, j, min1 = INT_MAX;
        for(int i = 0; i < strs.size(); i++){
            int n = strs[i].size();
            min1 = min(min1, n);
        }

        if(min1 == INT_MAX) min1 = 0;

        string ans = "";
        for(int j = 0; j < min1; j++){
            bool flag = true;
            char curr = strs[0][j];

            for(int i = 1; i < strs.size(); i++){
                if(strs[i][j] != curr){
                    flag = false;
                    break;

                }
            }

            if(flag){
                ans.push_back(curr);
            }else{
                break;
            }
        }

        return ans;
    }
};

int main() {
	string s, word;

	getline(cin, s);
	vector<string> strs;
	stringstream Str(s);
	while(getline(Str, word, ' ')) {
		strs.push_back(word);
	}

	string result = LongestCommonPrefix().longestCommonPrefix(strs);
	cout << result;
	return 0;
}

