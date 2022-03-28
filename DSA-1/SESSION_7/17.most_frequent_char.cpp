#include <bits/stdc++.h>
using namespace std;

// TODO: Implement this method
pair<int, char> findMostFrequent(string text) {
    unordered_map<char, int> hash;
    pair<char, int> res;

    for(int i = 0; i < text.size(); i++){
        hash[text[i]]++;
    }

    int max_count = 0; 
    char res_char = '\0';

    for(auto i : hash){
        if(i.second > max_count || (i.second == max_count && (int(i.first) < int(res_char)))){
            res_char = i.first;
            max_count = i.second;
        }
    }

    return {max_count, res_char};
}

// NOTE: Please do not modify this function
int main(){
    string text;
    getline(cin, text);

    char mostFrequent;
    int frequency;
    
    tie(frequency, mostFrequent) = findMostFrequent(text);
    cout << mostFrequent << " " << frequency << "\n";
}
