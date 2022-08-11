#include <bits/stdc++.h>
using namespace std;

vector<int> mathProfessor(int n,vector<string>&v,string B){
    vector<int> ans;
    map<char, int> mb;

    for(int i = 0; i < B.size(); i++){
        mb[B[i]]++;
    }

    for(int i = 0; i < n; i++){
        int sum = 0;
        map<char, int> m1;
        for(int j = 0; j < v[i].size(); j++){
            char curr = v[i][j];
            m1[curr]++;

            if(m1[curr] < 2 && mb[curr]){
                sum++;
            }

        }
        ans.push_back(sum);
    }

    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<string>v;
    string B;
    cin>>B;
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        v.push_back(x);
    }
    vector<int>ans= mathProfessor(n,v,B);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }

}