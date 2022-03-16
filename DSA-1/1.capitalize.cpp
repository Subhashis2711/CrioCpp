#include <bits/stdc++.h>
using namespace std;

bool isLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return true;
    }
    return false;
}

char capitalizeChar(char ch){
    if(isLowerCase(ch)){
        return ch - 'a' + 'A';
    }
    return ch;
}

// TODO: Implement this method
string capitalise(string para){
    int len = para.size();
    for(int i = 0; i < len; i++){
        if(i == 0 || (i > 0 && para[i-1] == ' ')){
            para[i] = capitalizeChar(para[i]);
        }
    }

    return para;
}

// NOTE: Please do not modify this function
int main(){
    string para;
    getline(cin, para);
    string new_para = capitalise(para);
    cout << new_para;
}

/*

*/