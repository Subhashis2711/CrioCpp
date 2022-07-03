#include "../SESSION-7/BinaryTree.hpp"


class Solution {
    public:
        TreeNode* findMin(TreeNode* root){
            TreeNode* temp = root;
            while(temp->left != NULL){
                temp = temp->left;
            }

            return temp;
        }

        TreeNode * inOrderSuccessor(TreeNode *root, TreeNode *givenNode) 
        {
            if(givenNode->right != NULL){
                return findMin(givenNode->right);
            }else{
                TreeNode* succesor = NULL;
                TreeNode* ancestor = root;

                while(ancestor != givenNode){
                    if(givenNode->val < ancestor->val){
                        succesor = ancestor;
                        ancestor = ancestor->left;
                    }else{
                        ancestor = ancestor->right;
                    }
                }

                return succesor;
            }
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

    int t;
    cin >> t;

    Solution s;
    while(--t){
        int m;
        cin >> m;
        cout<<s.inOrderSuccessor(b1.getRoot());
    } 
}