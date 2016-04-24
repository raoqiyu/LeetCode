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
    int minDepth(TreeNode* root) {
        // BFS
        int depth = 0;
        queue<TreeNode*> levelNode;
        if(root) levelNode.push(root);
        while(!levelNode.empty()){
            depth++;
            int n_nodes = levelNode.size();
            for(int i = 0; i < n_nodes; i++){
                TreeNode* tmp = levelNode.front();
                if(!tmp->left && !tmp->right)
                    return depth;
                if(tmp->left)
                    levelNode.push(tmp->left);
                if(tmp->right)
                    levelNode.push(tmp->right);
                levelNode.pop();
            }
        }
        return depth;
    }
};
