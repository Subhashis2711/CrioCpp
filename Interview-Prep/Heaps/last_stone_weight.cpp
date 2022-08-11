/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // 1.Create a MAX-HEAP and push all the elements to it.
        priority_queue<int, vector<int> > stone_heap;
        int n = stones.size();

        for(int i = 0; i < n; i++){
            stone_heap.push(stones[i]);
        }

        /* 
        2.Extract first two largest element, find difference and push
        to the MAX-HEAP. Repeat the process till number of elements 
        become less or equal to 1.
        */ 
       int first, second;
       while(n > 1){
            first = stone_heap.top();
            stone_heap.pop();
            second = stone_heap.top();
            stone_heap.pop();
            n -= 2;

            int diff = first - second;
            if(diff > 0){
                stone_heap.push(diff);
                n += 1;
            }
        }
       // Check if MAX-HEAP is not empty return the top element, else return 0.  
        if(!stone_heap.empty()){
            return stone_heap.top();

        }
        return 0;
    }
};