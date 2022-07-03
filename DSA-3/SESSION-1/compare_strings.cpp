#include <bits/stdc++.h>
using namespace std;

bool backspaceStringCompare(string S, string T){
    bool result = true;
    stack<char> s1;
    stack<char> s2;

    for(int i = 0; i < S.size(); i++){
        if(S[i] != '#'){
            s1.push(S[i]);
        }else if(!s1.empty()){
            s1.pop();
        }
    }

    for(int j = 0; j < T.size(); j++){

        if(T[j] != '#'){
            s2.push(T[j]);
        }else if(!s2.empty()){
            s2.pop();
        }
    }

    if(s1.empty() && s2.empty()){
        result = true;
    }else if(s1.empty() || s2.empty()){
        result = false;
    }else{
        while(!s1.empty() && !s2.empty()){
            if(s1.top() != s2.top()){
                result = false;
                break;
            }
            s1.pop();
            s2.pop();

        }
        if(!s1.empty() || !s2.empty()){
            result = false;
        }
    }

    return result;
}

int main(){
    int tests;
    cin >> tests;
    while (tests--) {
        string S, T;
        cin >> S;
        cin >> T;
        bool result = backspaceStringCompare(S, T);
        if (result) {
            cout << "true" << "\n";
        }
        else {
            cout << "false" << "\n";
        }
    }
}