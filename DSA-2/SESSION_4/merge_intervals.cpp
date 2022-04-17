#include <bits/stdc++.h>

using namespace std;

class MergeIntervals {
    public:
    
    static bool cmp_intervals(const vector<long long int>& i1, const vector<long long int>& i2){
        if(i1[0] <= i2[0]){
            return true;
        }

        return false;
    }

    vector<vector<long long int>> mergeIntervals(vector<vector<long long int>>& intervals) {
        stack<vector<long long int>> s;
        vector<vector<long long int>> res;

        if(intervals.size() < 1){
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), cmp_intervals);

        s.push(intervals[0]);

        for(long long int i = 1; i < intervals.size(); i++){
            vector<long long int> top = s.top();

            if(top[1] < intervals[i][0]){
                s.push(intervals[i]);
            }else if(top[1] <= intervals[i][1]){
                top[1] = intervals[i][1];
                s.pop();
                s.push(top);
            }
        }

        cout << intervals.size() << endl;

        int j = s.size();
        int s_size = s.size();
        while(!s.empty()){
            vector<long long int> t;
            t = s.top();
            intervals[--j] = t;
            s.pop();
        }
        
        intervals.resize(s_size);
        
        return intervals;
    }

       
    
};

int main() {
    long long int n;
    cin >> n;
    vector<vector<long long int>> nums(n,vector<long long int> (2, 0));
    for(long long int i=0;i<n;i++)
    {
        for(long long int j=0;j<2;j++)
        {
            cin>>nums[i][j];
        }
        cout<<"\n";
    }
    vector<vector<long long int>> result = MergeIntervals().mergeIntervals(nums);
    for(long long int i=0;i<nums.size();i++)
    {
        for(long long int j=0;j<2;j++)
        {
            cout<<nums[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}