#include "../SESSION-7/BinaryTree.hpp"

TreeNode* findKthSmallest(TreeNode* root, int &k){
    if(!root) return root;

    TreeNode* left = findKthSmallest(root->left, k);
    if(left != NULL) return left;

    k--;
    if(k==0) return root;

    return findKthSmallest(root->right, k);
}

int kthSmallestElementInABst(TreeNode* root, int k) {

    TreeNode* node = findKthSmallest(root, k);
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

    int result = kthSmallestElementInABst(b1.getRoot(), k);
    cout<<result<<endl;
}