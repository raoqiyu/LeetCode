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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        pathofgivenSum.clear();
        pathSumHelper(root, sum, tmp);
        return pathofgivenSum;
    }
    
private:
    vector<vector<int>> pathofgivenSum;
    void pathSumHelper(TreeNode* root, int sum, vector<int> &tmp)
    {
        if(root == NULL) return;
        if(root->val == sum && root->left == NULL && root->right == NULL){
            tmp.push_back(root->val);
            pathofgivenSum.push_back(tmp);
            tmp.pop_back();
            return;
        }
        
        tmp.push_back(root->val);
        pathSumHelper(root->left , sum - root->val, tmp);
        pathSumHelper(root->right, sum - root->val, tmp);
        tmp.pop_back();
    }
};
