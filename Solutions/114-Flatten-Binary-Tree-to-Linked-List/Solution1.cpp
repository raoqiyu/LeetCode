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
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        TreeNode* prev_left  = root->left;
        TreeNode* prev_right = root->right;
        flatten(root->left);
        flatten(root->right);
        
        root->left  = NULL;
        root->right = prev_left;
        TreeNode* right_most = root;
        while(right_most->right)
            right_most = right_most->right;
            
        right_most->right = prev_right;
    }
};
