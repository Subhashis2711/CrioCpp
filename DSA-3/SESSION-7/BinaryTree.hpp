#include "./TreeNode.hpp"
// #include <bits/stdc++.h>
// using namespace std;

class BinaryTree{
    public:
    TreeNode* root = NULL;

    BinaryTree(TreeNode* _root=NULL){
        root = _root;
    }

    TreeNode* insertToTree(long root_val, long left_val, long right_val, TreeNode* temp_root){
       if(temp_root == NULL && root_val != -1){
            temp_root = new TreeNode(root_val);
            temp_root->left = (left_val != -1)? new TreeNode(left_val): NULL;
            temp_root->right = (right_val != -1)? new TreeNode(right_val): NULL;

            root = temp_root;
        }else{
            if(temp_root->left && temp_root->left->val == root_val){
                temp_root = temp_root->left;
            }else if(temp_root->right && temp_root->right->val == root_val){
                temp_root = temp_root->right;
            }else if(root->right && root->right->val == root_val){
                temp_root = root->right;
            }

            if(temp_root){
                temp_root->left = (left_val != -1)? new TreeNode(left_val): NULL;
                temp_root->right = (right_val != -1)? new TreeNode(right_val): NULL;
            }
        }

        return temp_root;
    }

    void printInorder(TreeNode* root){
        if(root == NULL) return;
        printInorder(root->left);
        cout<<root->val<<" ";
        printInorder(root->right);
    }

    void printPreorder(TreeNode* root){
        if(root == NULL) return;
        cout<<root->val<<" ";
        printPreorder(root->left);
        printPreorder(root->right);
    }

    void printPostorder(TreeNode* root){
        if(root == NULL) return;
        printPostorder(root->left);
        printPostorder(root->right);
        cout<<root->val<<" ";

    }

    TreeNode* getRoot(){
        return root;
    }

    TreeNode* findNode(TreeNode* node, int key)
    {
        if(node == NULL) return NULL;
    
        if(node->val == key) return node;
    
        TreeNode* leftNode = findNode(node->left, key);
        if(leftNode) return leftNode;
    
        
        TreeNode* rightNode = findNode(node->right, key);
    
        return rightNode;
    }

};

