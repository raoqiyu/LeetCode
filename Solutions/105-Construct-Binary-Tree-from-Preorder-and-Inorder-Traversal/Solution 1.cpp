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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int cnt = inorder.size();
        map<int, int> inorder_map;
        for(int i = 0; i < cnt; i++){
            inorder_map[inorder[i]] = i;
        }
        return buildTree(preorder, inorder_map, 0, 0, cnt);
    }
    
private:
    TreeNode* buildTree(vector<int>& preorder, map<int, int>& inorder_map, int pre_idx, int in_offset, int len) {
        if(len == 0) return NULL;
        
        TreeNode* root = new TreeNode(preorder[pre_idx]);
        int in_idx = inorder_map[preorder[pre_idx]];
        int new_len = in_idx - in_offset;

        root->left = buildTree(preorder, inorder_map, pre_idx+1, in_offset, new_len);
        root->right = buildTree(preorder, inorder_map, pre_idx+new_len+1, in_offset+new_len+1, len-new_len-1);
        
        return root;
    }
};
