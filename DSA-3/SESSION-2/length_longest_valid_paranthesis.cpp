#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s){
    stack<int> st;
    int ans = 0;
    st.push(-1);

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push(i);
        }else{
            st.pop();
        }

        if(st.empty()){
            st.push(i);
        }

        ans = max(ans, (i - st.top()));
    }

    

    return ans;
}


int main(){
    string S;
    cin >> S;
    int ans = longestValidParentheses(S);
    cout << ans;
}
