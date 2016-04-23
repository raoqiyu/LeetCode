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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right){
        if(left == right) return NULL;
        
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
    
        root->left  = sortedArrayToBST(nums, left, mid);
        root->right = sortedArrayToBST(nums, mid+1, right);
        
        return root;

        
    }
};
