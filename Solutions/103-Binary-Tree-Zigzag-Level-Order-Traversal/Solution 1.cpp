/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Breadth-first Search
        // iterative solution
        vector<vector<int>> ret;
        if(root == NULL) return ret;
        queue<TreeNode* > level_que;
        level_que.push(root);
        bool zigzag = false;
        while(!level_que.empty()){
            int level_size = level_que.size();
            vector<int> level_node;
            for(int i = 0; i < level_size; i++){
                TreeNode* curr = level_que.front(); level_que.pop();
                level_node.push_back(curr->val);
                // Next level
                if(curr->left != NULL) level_que.push(curr->left);
                if(curr->right != NULL) level_que.push(curr->right);
            }
            if(zigzag == false)
                ret.push_back(level_node);
            else{
                reverse(level_node.begin(), level_node.end());
                ret.push_back(level_node);
            }
            zigzag = !zigzag;
        }
        
        return ret;        
    }
};
