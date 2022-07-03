#include "../SESSION-7/BinaryTree.hpp"

unordered_map<int, int> mp;

TreeNode* buildTree(vector<int> &pre, vector<int> &in, int s_idx, int e_idx){
    static int pre_idx = 0;

    if(s_idx > e_idx) return NULL;

    TreeNode* root = new TreeNode(pre[pre_idx++]);

    if(s_idx == e_idx) return root;

    int i = mp[root->val];

    root->left = buildTree(pre, in, s_idx, i-1);
    root->right = buildTree(pre, in, i+1, e_idx);

    return root;
}

TreeNode* constructBinaryTreeFromPreorderAndInorderTraversal(vector<int> &preorder
, vector<int> &inorder) {
    for(int i = 0; i < inorder.size(); i++){
        mp[inorder[i]] = i;
    }

    return buildTree(preorder, inorder, 0, inorder.size()-1);
}

int main(){
    int n;
    cin >> n;

    vector<int> in(n), pre(n);
    for(int i = 0; i < n; i++){
        cin >> in[i];
    }

    for(int i = 0; i < n; i++){
        cin >> pre[i];
    }

    TreeNode* result = constructBinaryTreeFromPreorderAndInorderTraversal(pre, in);
    BinaryTree b1(result);

    b1.printInorder(b1.getRoot());
    cout<<endl;
    b1.printPreorder(b1.getRoot());
}