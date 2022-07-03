#include "../SESSION-7/BinaryTree.hpp"

/*
Function to fill the map with vertical level and its first element to get the top view
of the given BT.
*/
void fillMap(TreeNode* root, int vertical, int horizontal, map<int, pair<int, int>> &m){
    // If no root return
    if(root == NULL) return;

    /*
    If map key as the current vertical level is not present (or) current horizontal level if less 
    than the horizontal level from the pair, then create/update the pair. 
    */
    if((m.find(vertical) == m.end()) || (horizontal < m[vertical].second)){
        m[vertical] = make_pair(root->val, horizontal);
    }

    /*
    Recursive function call for left and right subtree by modifying the vertical level(increase
    for right and decrease for left) and increasing the horizontal level. 
    */
    fillMap(root->left, vertical-1, horizontal+1,  m);
    fillMap(root->right, vertical+1, horizontal+1, m);
    return;
}

/*
Function to find the top view of a gievn BT.
*/
vector<int> topViewBinaryTree(TreeNode* root) {
    vector<int> ans;

    /*
    Initialize a map with key as vertical level(int) and value as pair of 
    first element of the vertical level(int) and horizontal level(int) (that has
    the least vertical level) 
    */
    map<int, pair<int, int>> m;

    /*
    Call fillMap function with parameters root, horizontal level, vertical level
    and the map
    */
    fillMap(root, 0, 0, m);

    for(auto i : m){
        ans.push_back(i.second.first);
    }

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

    vector<int> result = topViewBinaryTree(b1.getRoot());
    for(auto i : result){
        cout<<i<<" ";
    }
}