#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinctElements(int n, int b, vector<int> a){
    vector<int> ans;
    unordered_map<int, int> m;
    int i = 0;

    for(int j = 0; j < n; j++){
        if(m.find(a[j]) != m.end()){
            m[a[j]]++;
        }else{
            m[a[j]] = 1;
        }

        if((j - i + 1) == b){
            ans.push_back(m.size());
            if(m[a[i]] == 1){
                m.erase(a[i]);
            }else{
                m[a[i]]--;
            }
            i++;
        }
    }

    return ans;

}


int main(){
    int n, b;
    cin>> n >> b;
    vector<int> a(n);
    for(auto &i: a)
        cin>> i;
    vector<int> result = countDistinctElements(n, b, a);
    assert( result.size() == max(0,n - b + 1) );
    for(auto &i: result){
        cout << i << " " ;
    }
}