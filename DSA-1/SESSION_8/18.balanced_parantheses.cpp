#include <bits/stdc++.h>
using namespace std;

class ValidParenthesis
{
unordered_map<char, int> symbols = {
    {'[', -1}, {'{', -2}, {'(', -3}, {']', 1}, {'}', 2}, {')', 3}
};
public:
	// Implement your solution here
	string isValid(string s)
	{
        stack<char> st;
        for(char bracket:s){
            if(symbols[bracket] < 0){
                st.push(bracket);
            }else{
                if(st.empty()) { return "false"; }
                char top = st.top();
                st.pop();

                if(symbols[top] + symbols[bracket] != 0){
                    return "false";
                }
            }
        }
        if(st.empty()) { return "true"; }
        else { return "false"; }
	}
};

// NOTE: Please do not modify this function
int main()
{
	string s;
	getline(cin, s);
	string result = ValidParenthesis().isValid(s);
	cout << result;
	return 0;
}