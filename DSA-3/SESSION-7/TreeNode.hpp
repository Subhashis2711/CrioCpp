#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        long val;
        TreeNode* left;
        TreeNode* right;
        TreeNode* next;
        TreeNode (long x) {
            val = x;
            left = NULL;
            right = NULL;
            next = NULL;
        }
};