#include<bits/stdc++.h>
using namespace std;

struct Comparator{
   bool operator()(vector<long long int>& a, vector<long long int>& b){
      return !(a[1] < b[1]);
   }
};

bool cmp_intervals(vector<long long int>& i1, vector<long long int>& i2){
    if(i1[0] < i2[0]){
        return true;
    }

    return false;
}

int meetingRooms(int n, vector<vector<long long int>>& time){
    if(time.size() < 1){
        return 0;
    }
    priority_queue<vector<long long int>, vector<vector<long long int>>, Comparator> pq;
    
    sort(time.begin(), time.end(), cmp_intervals);
    
    int ret;
    pq.push(time[0]);
    for(int i = 1; i < n; i++) {
        vector<long long int> current = time[i];
        vector<long long int> earliest = pq.top();
        pq.pop();


        if(current[0] >= earliest[1])
           earliest[1] = current[1];
        else{
            pq.push(current);
        }

        pq.push(earliest);
    }

    ret = pq.size();
    return ret;
}

int main(){
    int n;
    cin>>n;
    vector<vector<long long int>>time(n);
    for (int i = 0; i < n; i++)
    {
        long long int s,e;
        cin>>s>>e;
        time[i].push_back(s);
        time[i].push_back(e);
    }
    int ans = meetingRooms(n,time);
    cout<<ans;
}