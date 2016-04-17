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
    bool isValidBST(TreeNode* root) {
        // Traverse the tree in inorder
        if(root != NULL){
            if(!isValidBST(root->left)) return false;
            
            if(prev != NULL && root->val <= prev->val) return false;
            prev = root;
            
            return isValidBST(root->right); 
            
        }
        return true;
    }
private:
    TreeNode *prev=NULL;
};
