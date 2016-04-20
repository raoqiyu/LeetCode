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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Breadth-first Search
        // Recursive solution
        vector<vector<int>> ret;
        
        levelOrder(root, ret, 1);
        
        return ret;
    }
private:
    void levelOrder(TreeNode* root, vector<vector<int>>& ret, int level){
        if(root == NULL) return;
        if(ret.size() == level-1){
            vector<int> lev;
            lev.push_back(root->val);
            ret.push_back(lev);
        }else{
            ret[level-1].push_back(root->val);
        }
        
        levelOrder(root->left, ret, level+1);
        levelOrder(root->right, ret, level+1);
    }
};
