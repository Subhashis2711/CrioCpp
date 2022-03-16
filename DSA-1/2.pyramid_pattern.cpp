#include <bits/stdc++.h>
using namespace std;

// TODO: Implement this method
vector<string> patternPrintingI(int n)
{
    vector<string> output;
    for(int i = 1; i <= n; ++i){
        string star_str = "";
        for(int j = 1; j <= i; ++j){
            if(i == j){
                star_str += "*";
            }else{
                star_str += "*_";
            }
            

        }
        output.push_back(star_str);
    }
    return output;
}

// NOTE: Please do not modify this function
int main()
{
    int n;
    cin >> n;
    vector<string> result = patternPrintingI(n);
    for (auto row : result)
    {
        for (auto ch : row)
        {
            cout << ch;
        }
        cout << "\n";
    }
}