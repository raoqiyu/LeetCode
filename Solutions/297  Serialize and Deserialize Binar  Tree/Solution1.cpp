/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    // levelorder traversal
    // use queue
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = "";
        if(root == NULL)
            return ret;
        queue<TreeNode*> levelNode;
        TreeNode* curr = NULL;
        levelNode.push(root);
        ret += to_string(root->val);
        while(!levelNode.empty()){
            curr = levelNode.front();
            levelNode.pop();
            if(curr->left){
                levelNode.push(curr->left);
                ret += " " + to_string(curr->left->val);
            }else{
                ret += " #";
            }
            if(curr->right){
                levelNode.push(curr->right);
                ret += " " + to_string(curr->right->val);
            }else{
                ret += " #";
            }
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        if(data.empty())
            return root;
        
        queue<TreeNode*> levelNode;
        TreeNode* curr = NULL;

        bool left = true;
        stringstream ss(data);
        string num;
        ss >> num;
        
        root = new TreeNode(stoi(num));
        
        curr = root;
        while(ss >> num){
            if(num == "#"){
                if(!left){
                    curr = levelNode.front();
                    levelNode.pop();
                }
            }else{
                if(left){
                    curr->left = new TreeNode(stoi(num));
                    levelNode.push(curr->left);
                }else{
                    curr->right = new TreeNode(stoi(num));
                    levelNode.push(curr->right);
                    curr = levelNode.front();
                    levelNode.pop();
                }
            }
            left = !left;
        }
        
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
