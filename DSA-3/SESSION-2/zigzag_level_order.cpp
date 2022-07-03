/*
// Definition for TreeNode
class TreeNode {
public:
    long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
*/
class BinaryTreeZigzagLevelOrderTraversal {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int> > level_order;

        int level = 0;

        q.push(root);

        while(!q.empty()){
            int current_level_size = q.size();
            vector<int> level_array;


            for(int i = 0; i < current_level_size; i++){
                TreeNode* current_node = q.front();
                q.pop();
                level_array.push_back(current_node->val);
                if(current_node->left) q.push(current_node->left);
                if(current_node->right) q.push(current_node->right);
            }

            if(level % 2 != 0){
                reverse(level_array.begin(), level_array.end());
            }
            ++level;

            level_order.push_back(level_array);
            

        }

        return level_order;

    }
};