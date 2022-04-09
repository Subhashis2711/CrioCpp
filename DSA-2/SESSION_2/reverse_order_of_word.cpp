#include <bits/stdc++.h>
using namespace std;

string reverseWordsInAString(string str){
    string temp = "";
    stack<string> s;
    string res = "";

    for(int i = 0; i < str.size(); i++){
        if(str[i] != ' '){
            temp.push_back(str[i]);
        }else if(temp != ""){
            s.push(temp);
            temp = "";
        }
    }
    if(temp != ""){
        s.push(temp);
    }

    while(s.empty() == false){
        res = res + s.top() + " ";
        s.pop();
    }
    res.pop_back();

    return res;
}


int main(){
    string str;
    getline(cin, str);
    cout<<reverseWordsInAString(str);
}