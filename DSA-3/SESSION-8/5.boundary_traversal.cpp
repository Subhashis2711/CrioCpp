#include "../SESSION-7/BinaryTree.hpp"

// Function to check if a node is leaf node or not.
bool isLeaf(TreeNode* root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    return false;
}

// Function to add all left boundary elements except leaf nodes.
void addLeftBoundary(TreeNode* root, vector<int> &ans){
    TreeNode* cur = root->left;
    while(cur){
        if(!isLeaf(cur)) ans.push_back(cur->val);
        if(cur->left){
            cur = cur->left;
        }else{
            cur = cur->right;
        }
    }
}

void addLeaves(TreeNode* root, vector<int> &ans){
    if(!root) return;

    if(isLeaf(root)){
        ans.push_back(root->val);
        return;
    }
    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}

void addRightBoundary(TreeNode* root, vector<int> &ans){
    stack<int> st;
    TreeNode* cur = root->right;
    while(cur){
        if(!isLeaf(cur)) st.push(cur->val);
        if(cur->right){
            cur = cur->right;
        }else{
            cur = cur->left;
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}

vector<int> binaryTreeBoundaryTraversal(TreeNode* root) {
    vector<int> ans;

    if(!root) return ans;
    if(!isLeaf(root)) ans.push_back(root->val);

    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);

    
    return ans;
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

    vector<int> result = binaryTreeBoundaryTraversal(b1.getRoot());

    for(auto i : result){
        cout<<i<<" ";
    }
}