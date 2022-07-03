#include<bits/stdc++.h>
using namespace std;

class Comparator{
    public:
        bool operator()(pair<string, int> s1, pair<string,int> s2){
            if(s1.second != s2.second){
                return s1.second > s2.second;
            }
            return s1.first < s2.first;
        }
};

vector<string> frequentWords(vector<string>& words , int k) {
    unordered_map<string, int> m;
    priority_queue<pair<string, int>, vector<pair<string,int>>, Comparator> pq;

    // Find the frequ=uency of every word using an unordered map
    for(int i = 0; i < words.size(); i++){
        if(m.find(words[i]) == m.end()){
            m[words[i]] = 1;
        }else{
            m[words[i]] ++;
        }
    }

    for(auto i : m){
        if(pq.size() < k){
            pq.push(i);
        }else if(pq.top().second < i.second){
            pq.pop();
            pq.push(i);
        }else if(pq.top().second == i.second && pq.top().first > i.first){
            pq.pop();
            pq.push(i);
        }
    }

    vector<string> result;

    while(!pq.empty()){
        pair<string, int> temp = pq.top();
        cout<<temp.first<<endl;
        result.push_back(temp.first);
        pq.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
	int n, k;
	cin >> n;
	vector<string> v(n);
	for ( int i = 0; i < n; i++) cin >> v[i];
	cin >> k;
	vector<string> ans = frequentWords(v, k);
	for ( auto it : ans) {
		cout << it << endl;
	}
}