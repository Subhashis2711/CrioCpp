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

bool isVowel(char ch){
    ch = capitalizeChar(ch);
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

// TODO: Implement this method
int countVowels(string s)
{
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        if(isVowel(s[i])){
            count += 1;
        }
    }

    return count;

}

// NOTE: Please do not modify this function
int main()
{
    string s;
    cin >> s;
    int result = countVowels(s);
    cout << result;
}
