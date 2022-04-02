#include <bits/stdc++.h>
using namespace std;
// TODO: Implement this method
int postfixExpression(string s)
{   
    string token;
    stack<int> st;

    istringstream ss(s); 

    vector<string> tokens; 

    while (ss >> token) tokens.push_back(token);

    for(auto ch: tokens){

        if(ch == "+" || ch == "-" || ch == "*" || ch =="/"){
            int x = st.top();
            st.pop();

            int y = st.top();
            st.pop();

            if(ch == "+"){
                st.push(y + x);
            }else if(ch == "-"){
                st.push(y - x);
            }else if(ch == "*"){
                st.push(y * x);
            }else if(ch == "/"){
                st.push(y / x);
            }
        }else{
            int num = stoi(ch);
            st.push(num);
        }
    }

    return st.top();
}

// NOTE: Please do not modify this function
int main()
{
    string s;
    getline(cin, s);
    int res = postfixExpression(s);
    cout << res << "\n";
}