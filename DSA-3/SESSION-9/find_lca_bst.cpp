#include "../SESSION-7/BinaryTree.hpp"


TreeNode* lowestCommonAncestorInBST(TreeNode *root, TreeNode *p, TreeNode *q) {
    if(root == NULL) return root;

    if(root->val > p->val && root->val > q->val){
        return lowestCommonAncestorInBST(root->left, p, q);
    }

    if(root->val < p->val && root->val < q->val){
        return lowestCommonAncestorInBST(root->right, p, q);
    }

    return root;
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

    int p, q;
    cin >> p >> q;

    TreeNode* node1 = b1.findNode(b1.getRoot(), p);
    TreeNode* node2 = b1.findNode(b1.getRoot(), q);


    TreeNode* result = lowestCommonAncestorInBST(b1.getRoot(), node1, node2);
    cout<<result->val<<endl;
}