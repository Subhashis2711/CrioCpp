#include <bits/stdc++.h>
using namespace std;

vector<int> largestSubarraySumZero(int n, vector<int> arr){
    vector<int> prefix;
    vector<int> res;
    unordered_map<int, int> m;

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        prefix.push_back(sum);
    }

    m[0] = -1;
    int max_length = 0;
    int start = 0, end = 0; 

    for(int i = 0; i < n; i++){
         if(m.find(prefix[i]) != m.end()){
            int length = i - m[prefix[i]];
            
            if(length > max_length){
                max_length = max(length, max_length);
                end = i;
                start = i - max_length + 1;

                // if(length != 1){
                //     start += 1;
                // }
            }

        }else{
            m[prefix[i]] = i;
        }
        
    }

    cout<<start<<"--"<<end<<endl;
    if(start == 0 && end == 0 && max_length == 0){
        res.push_back(-1);
    }else{
        for(int i = start; i <= end; i++){
            res.push_back(arr[i]);
        }
    }

    return res;
}


int main(){
    
    int n;
    cin>>n;

    vector<int> arr(n);
    for(auto &i:arr) {
        cin>>i;
    }

    vector<int> longestSubarray = largestSubarraySumZero(n, arr);
    
    for(auto i:longestSubarray) {
        cout<<i<<" ";
    }
}