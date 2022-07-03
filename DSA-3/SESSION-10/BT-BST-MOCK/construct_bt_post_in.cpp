/*
Problem Description
Given postorder and inorder traversal of a tree, construct the binary tree and return its root. Note: You may assume that duplicates do not exist in the tree.

Input format
First line contains N, number of elements in the tree.

Next line contains N space separated integers, denoting postorder.

Next line contains N space separated integers, denoting inorder.

Output format
Print two lines, first line contains N space separated integers denoting postorder.

Second line contains N space separated integers, denoting inorder.

Note: You just have to return the root of the tree. The input/output is already handled.

Sample Input 1
5

10 4 5 7 8

8 10 4 7 5

Sample Output 1
10 4 5 7 8

8 10 4 7 5
*/
#include "../SESSION-7/BinaryTree.hpp"

// Declare a global map.
unordered_map<int, int> mp;

// Function to build a Tree with inorder and postorder traversals.
TreeNode* buildTree(vector<int> &in, int i_s, int i_e, vector<int> &post, int p_s, int p_e){

    // If the starting indices are greater than the end indices return NULL.
    if(i_s > i_e || p_s > p_e) return NULL;

    /*
    Create a root node using last index of postorder traversal array, as the last element
    is always the root in postorder traversal.
    */
    TreeNode* root = new TreeNode(post[p_e]);

    /* 
    Find the index of root in inorder traversal array using the map.
    Also find the no. of elements to the left of the root(that denotes the left subtree)
    by substracting start index of inorder from root index of inorder.
    */
    int in_root = mp[post[p_e]];
    int nums_left = in_root - i_s;

    /*
    Recursively call the function for the left subtree by passing left part of tree
    before root for inorder and nums_left number of elements from starting of postorder.
    Similarly for the right subtree. 
    */
    root->left = buildTree(in, i_s, in_root - 1, post, p_s, p_s + nums_left - 1);
    root->right = buildTree(in, in_root + 1, i_e, post, p_s + nums_left , p_e - 1);

    return root;
}

// Function to construct a binary tree, given postorder and inorder traversals
TreeNode* constructBinaryTreeFromPostorderAndInorderTraversal(vector<int> &postorder
, vector<int> &inorder) {
    // Get the size of inorder and postorder traversal arrays.
    int in_size = inorder.size();
    int post_size = postorder.size();

    // If sizes are different return NULL
    if(in_size != post_size) return NULL;

    // Store the index against values in a map for easy access.
    for(int i = 0; i < in_size; i++){
        mp[inorder[i]] = i;
    }

    /* 
    Call function to build free by passing the first and last index of inorder and
    postorder traversal array.
    */
    return buildTree(inorder, 0, in_size-1, postorder, 0, post_size-1);
}

int main(){
    int n;
    cin >> n;

    vector<int> in(n), post(n);
    for(int i = 0; i < n; i++){
        cin >> in[i];
    }

    for(int i = 0; i < n; i++){
        cin >> post[i];
    }

    TreeNode* result = constructBinaryTreeFromPostorderAndInorderTraversal(post, in);
    BinaryTree b1(result);

    b1.printInorder(b1.getRoot());
    cout<<endl;
    b1.printPreorder(b1.getRoot());
}