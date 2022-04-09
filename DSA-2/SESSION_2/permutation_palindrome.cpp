#include<bits/stdc++.h>
using namespace std;

bool isPermutationPalindrome(string &s) {
    bool res = true;
    unordered_map<char, int> m;
    for(int i=0; i < s.size(); i++){
        if(m.find(s[i]) != m.end()){
            m[s[i]]++;

        }else{
            m[s[i]] = 1;

        }
    }

    int odd = 0;
    for(auto item: m){
        if(item.second % 2 != 0){
            odd++;
        }
    }

    if(odd > 1){
        res = false;
    }

    return res;
}

int main()
{
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		bool answer = isPermutationPalindrome(s);
		if(answer) {
			cout << "True\n";
		} else {
			cout << "False\n";
		}
	}
	return 0;
}
