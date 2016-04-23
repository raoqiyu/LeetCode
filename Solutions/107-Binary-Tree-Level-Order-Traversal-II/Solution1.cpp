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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<TreeNode*> level_nodes;
        level_nodes.push_back(root);
        vector<vector<int>> ret;
        if(root == NULL) return ret;
        vector<int> level_sizes;
        level_sizes.push_back(0);
        int layer = 0;
        bool LOOP = true;
        while(LOOP){
            LOOP = false;
            layer++;
            int size = level_nodes.size();
            level_sizes.push_back(size);
            cout <<'\n' <<  size << endl;
            for(int i = level_sizes[layer-1]; i < level_sizes[layer]; i++){
                cout << i << " ";
                TreeNode* curr = level_nodes[i];
                
                if(curr->left  != NULL){ 
                    level_nodes.push_back(curr->left);
                    LOOP = true;
                }
                if(curr->right != NULL){
                  level_nodes.push_back(curr->right);
                  LOOP = true;
                } 
            }
        }
        
        for(int i = layer; i > 0; i--){
            vector<int> node;
            for(int j = level_sizes[i-1]; j < level_sizes[i]; j++)
                node.push_back(level_nodes[j]->val);
            ret.push_back(node);
        }
        return ret;
    }
};
