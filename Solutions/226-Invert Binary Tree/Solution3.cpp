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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
            
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        
        return root;
    }
};
