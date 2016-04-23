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
    bool isBalanced(TreeNode* root) {
        return depth(root);
    }
private:
    int depth(TreeNode* root){
        if(root == NULL) return 1;
        int left = depth(root->left);
        int right = depth(root->right);
        if(left == 0 || right == 0 || abs(left-right)>1) return 0;
        
        return 1 + max(left, right);
    }
};
