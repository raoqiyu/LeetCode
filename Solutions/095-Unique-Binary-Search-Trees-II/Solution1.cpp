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
    vector<TreeNode*> generateTrees(int n) {
        // Make a node as root, make the left node as left or right tree
        if(n == 0) return vector<TreeNode*>();
        return generateTrees(1, n);
    }
private:
    vector<TreeNode*> generateTrees(int start, int end){
        vector<TreeNode*> ret;
        
        if(start > end){
            ret.push_back(NULL);
            return ret;
        }
        
        for(int k = start; k <= end; k++){
            vector<TreeNode*> left  = generateTrees(start, k-1);
            vector<TreeNode*> right = generateTrees(k+1, end);
            for(int i = 0; i < left.size(); i++)
                for(int j = 0; j < right.size(); j++){
                    TreeNode* root = new TreeNode(k);
                    root->left = left[i];
                    root->right = right[j];
                    ret.push_back(root);
                }
        }
        return ret;
    }
};
