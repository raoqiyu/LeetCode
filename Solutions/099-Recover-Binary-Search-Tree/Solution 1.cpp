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
    void recoverTree(TreeNode* root) {
        findMistake(root);
        if(err1 != NULL){
            int val = err1->val;
            err1->val = err2->val;
            err2->val = val;
        }
    }
private:
    TreeNode *prev=NULL, *err1=NULL, *err2=NULL;
    bool findMistake(TreeNode* root){
        if(root != NULL){
            bool found = findMistake(root->left);
            
            if(prev != NULL && prev->val > root->val){
                if(err1 == NULL)
                    err1 = prev;
                else{
                    found = true;
                }
                 err2 = root;
            }
            
            prev = root;
            // if found , donot need search the right subtree
            return found || findMistake(root->right);
        }
        // not found
        return false;
    }
};
