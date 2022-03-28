#include <bits/stdc++.h>
using namespace std;

// TODO: Implement this method
int mostRepeatedTemperature(vector<int> temperatures){
    unordered_map<int, int> m;
    for(int i = 0; i < temperatures.size(); i++){
        m[temperatures[i]] += 1;
    }

    int max_count = 0;
    int res = -1;

    for(auto i : m){
        if(i.second > max_count){
            res = i.first;
            max_count = i.second;


        }
    }

    return res;
}

// NOTE: Please do not modify this function
int main(){
    int n;
    cin >> n;
    vector<int> temperatures(n);
    for (int i = 0 ; i < n ; ++i) {
        cin >> temperatures[i];
    }

    int result = mostRepeatedTemperature(temperatures);
    cout << result << "\n";
}