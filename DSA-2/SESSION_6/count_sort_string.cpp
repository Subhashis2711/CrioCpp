#include <bits/stdc++.h>
using namespace std;

string countSort(int n, string s){
    map<char,int> m;
    string res = "";
    for(int i = 0; i < n; i++){
        if(m.find(s[i]) != m.end()){
            m[s[i]] ++;
        }else{
            m[s[i]] = 1;
        }
    }

    for(auto i:m){
        res += string(i.second, i.first);
    }

    return res;
}


int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string result = countSort(n, s);
    cout<< result << "\n";
}