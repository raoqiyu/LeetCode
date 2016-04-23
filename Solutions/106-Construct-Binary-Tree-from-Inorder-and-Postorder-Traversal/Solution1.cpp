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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        
        return buildTree(postorder, inorder, 0, len-1, 0, len-1);
    }
private:
    TreeNode *buildTree(vector<int>& postorder, vector<int>& inorder, int post_first, int post_last, int in_first, int in_last){
        
        if(post_last == post_first) return new TreeNode(postorder[post_last]);
        if( (in_last < in_first) || (post_last <  post_first)) return NULL;
        
        TreeNode* root = new TreeNode(postorder[post_last]);
        
        int in_idx = in_first;
        while(inorder[in_idx] != postorder[post_last])
            in_idx++;
        int new_len = in_idx - in_first;
        //cout << post_last << " " << inorder_idx << " " << inorder_offset << " " << len << " " << new_len << endl;
        //cout << "go left" << endl;
        root->left  = buildTree(postorder, inorder, post_first, post_first+new_len-1, in_first, in_last-1);
        //cout << "go right" << endl;
        root->right = buildTree(postorder, inorder, post_first+new_len, post_last-1, in_idx+1, in_last);
        
        return root;
    }
};
