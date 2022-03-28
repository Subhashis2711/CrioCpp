#include <bits/stdc++.h>
using namespace std;
// TODO: Implement this method
int postfixExpression(string s)
{
    stack<int> st;

    for(char ch: s){
        if(ch != ' '){
            if(ch > '0' and ch < '9'){
                st.push(ch - '0');
            }else{

                int x = st.top();
                st.pop();

                int y = st.top();
                st.pop();

                if(ch == '+'){
                    st.push(y + x);
                }else if(ch == '-'){
                    st.push(y - x);
                }else if(ch == '*'){
                    st.push(y * x);
                }else if(ch == '/'){
                    st.push(y / x);
                }
            }

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