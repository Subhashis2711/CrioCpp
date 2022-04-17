#include <bits/stdc++.h>
using namespace std;

string subArrayExists(int n , vector<int> arr) 
{ 
    // string result;
    vector<int> prefix;
    unordered_set<int> s;
    
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        prefix.push_back(sum);
    }

    for(int i = 0; i < n; i++){
        if(prefix[i] == 0){
            return "Yes";
        }
        if(s.find(prefix[i]) != s.end()){
            return "Yes";
        }

        s.insert(prefix[i]);
    }

    return "No";
} 

int main()
{
    int tests;
    cin>>tests;
    while(tests--)
    {
        int n;
        cin>>n;
        vector<int > arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        string answer = subArrayExists(n,arr);
        cout<<answer<<"\n";
    }
    return 0;
}