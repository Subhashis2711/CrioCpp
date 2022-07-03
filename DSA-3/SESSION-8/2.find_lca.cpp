/*
Problem Description
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. LCA between two nodes p and q is defined as the lowest node in the tree that has both p and q as descendants (where we allow a node to be a descendant of itself)

Note: For the solution method provided, the input parameters are the nodes p and q, not node values. The return value expected from the method is the LCA node and not the node’s value. The below Input and Output format show node values which the Driver file will take care of; the user doesn’t have to edit the Driver code.

Input format
Line 1 has T: no of test cases given.

Line 2 to X: First test case details with first set of lines giving the binary tree structure (refer section below for the format) and last line giving two node values (integers) whose LCA node has to be found.

Line X+1 to Y: Second Test case details and so on.

Output format
Print the value of the node which is the common ancestor of two nodes.

Constraints
1 <= T <= 1000

1 <= N <= 10000, Number of nodes in the tree

0 <= Node values <= 10^9

It is guaranteed that the sum of the number of tree nodes for all test cases will be < 500000.

Sample Input 1
1

5

2 3 7 8 9

1 2 3

2 4 5

3 -1 -1

4 -1 -1

5 -1 -1

7 2

Sample Output 1
2
*/

#include "../SESSION-7/BinaryTree.hpp"


class CommonAncestor {
public:
    TreeNode* commonAncestor(TreeNode* root, TreeNode * p , TreeNode* q) {
        // Return NULL if root is NULL
        if(root == NULL) return root;

        // If any of two nodes(p or q)
        if(root == p || root == q) return root;

        /*
        Call recursive function on root's left and right to find if nodes(p and q) 
        in left or right
        */
        TreeNode* leftCommonAncestor = commonAncestor(root->left, p, q);
        TreeNode* rightCommonAncestor = commonAncestor(root->right, p, q);

        /*
        1. If both left and right are not null, that means one node is present in
        left and one in right. So the LCA is root.
        2. If both the nodes are present in right(left is NULL), return right
        3. Viceversa of 2
        */
        if(leftCommonAncestor && rightCommonAncestor) return root;
        if(!leftCommonAncestor && rightCommonAncestor) return rightCommonAncestor;
        if(leftCommonAncestor && !rightCommonAncestor) return leftCommonAncestor;

        return NULL;
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

    int p, q;
    cin >> p >> q;

    TreeNode* node1 = b1.findNode(b1.getRoot(), p);
    TreeNode* node2 = b1.findNode(b1.getRoot(), q);


    CommonAncestor c;
    TreeNode* result = c.commonAncestor(b1.getRoot(), node1, node2);
    cout<<result->val<<endl;
}