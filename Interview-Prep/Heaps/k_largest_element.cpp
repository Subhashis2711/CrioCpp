

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve_heap(vector<int> &A, int B) {
        vector<int> result;
        priority_queue<int> pq;
        
        // 1. Build a heap by pushing all the elements
        for(int i = 0; i < A.size(); i++){
            pq.push(A[i]);
        }
        
        // 2. Extract max element k times and store in resulatant vector.
        while(B--){
            result.push_back(pq.top());
            pq.pop();
        }
        
        return result;
    }
};
        