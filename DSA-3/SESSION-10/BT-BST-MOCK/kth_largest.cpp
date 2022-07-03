/*
Problem Description
Given a Binary Search Tree (BST) and a positive integer k, find the k’th largest element in the Binary Search Tree.

Input format
First line contains an integer n - Number of nodes.

Second line contains n space separated integers - The value of nodes.

Next n lines contain 3 space separated integers i, l, r describing left and right child of ith node as l and r respectively.
*/

#include "../../SESSION-7/BinaryTree.hpp"

// Function to find the kth largest element from a BST.
TreeNode* findKthLargest(TreeNode* root, int &k){
    if(!root) return root;

    /*
    Traverse the tree in reverse INORDER traversal and keep track of the
    number of visited nodes.
    */
    TreeNode* right = findKthLargest(root->right, k);
    if(right != NULL) return right;

    k--;
    // If the number of visited nodes equals to 0 return root.
    if(k==0) return root;

    return findKthLargest(root->left, k);
}

int kthLargestElementInABst(TreeNode* root, int k) {

    TreeNode* node = findKthLargest(root, k);
    return node->val;

}

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

    int k;
    cin >> k;

    int result = kthLargestElementInABst(b1.getRoot(), k);
    cout<<result<<endl;
}