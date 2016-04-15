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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        vector<int> ret;
        if(root == NULL) return ret;
        while(!s.empty()){
            TreeNode* node = s.top();
            if(node->left == NULL){
                s.pop();
                ret.push_back(node->val);
                if(node->right != NULL)
                    s.push(node->right);
            }else{
                s.push(node->left);
                node->left = NULL;
            }
        }
        return ret;
    }
};
