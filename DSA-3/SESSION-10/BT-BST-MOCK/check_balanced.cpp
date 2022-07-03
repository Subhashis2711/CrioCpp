/*
Problem Description
Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.

Input format
Line 1: Number of Test cases (T)

Line 2 to X: First Test Case binary tree structure (refer section below for the format)

Line X+1 to Y: Second Test Case details and so on.

Output format
For each test case, print N (number of nodes in the tree) space separated values of next nodes on a separate line. If nothing exists in the next print "null" without quotes.

Constraints
1 <= T <= 100

1 <= N <= 100000

0 <= Value of nodes <= 10^9

It is guaranteed that the sum of the number of tree nodes across all test cases will be less than 500000.

Sample Input 1
1

3

1 2 3

1 2 3

2 -1 -1

3 -1 -1

Sample Output 1
Yes
*/
#include "../../SESSION-7/BinaryTree.hpp"

class CheckBalanced {
public:
    // Function to check if a given tree is balanced or
    bool isBalanced(TreeNode* root, int &height){
        int lh = 0, rh = 0;

        int left = 0, right = 0;

        if (root == NULL) {
            height = 0;
            return true;
        }

        left = isBalanced(root->left, lh);
        right = isBalanced(root->right, rh);

        height = (lh > rh ? lh : rh) + 1;

        if (abs(lh - rh) >= 2){
            return false;
        }else{
            return left && right;

        }
    }

    bool checkBalanced(TreeNode *root)
    {
        int height = 0;
        return isBalanced(root, height);
    }
};

int main(){
    int n;
    cin >> n;

    vector<int> node_vals(n);
    for(int i = 0; i < n; i++){
        cin >> node_vals[i];
    }

    int root_idx, left_idx, right_idx;
    BinaryTree b1;
    TreeNode* root = NULL;

    for(int i = 0; i < n; i++){
        cin>>root_idx>>left_idx>>right_idx;
        int root_val = (root_idx > 0)? node_vals[root_idx-1] : -1;
        int left_val = (left_idx > 0)? node_vals[left_idx-1] : -1;
        int right_val = (right_idx > 0)? node_vals[right_idx-1] : -1;

        root = b1.insertToTree(root_val, left_val, right_val, root);
    }

    CheckBalanced c1;
    cout<<c1.checkBalanced(b1.getRoot())<<endl;
}