class Solution {
    struct TreeNode{
        int val;
        int cnt;
        TreeNode *left, *right;
        TreeNode(int value = -1, int small = 0){
            left = right = NULL;
            val = value;
            cnt = small;
        }
    };
public:
    vector<int> countSmaller(vector<int>& nums) {
        // BInary Search Tree
        // scan the array from right to left and construct the BST
        TreeNode * root = NULL;
        deque<int> ret;
        for(int i = nums.size()-1; i >= 0; i--){
            ret.push_front(addNode(root, nums[i]));
        }
        
        return vector<int>(ret.begin(), ret.end());
    }
private:
    int addNode(TreeNode* &root, int val){
        if(root == NULL){
            cout << "IN : " << val << endl;
            root = new TreeNode(val, 0);
            return 0;
        }

        if(val < root->val){
            root->cnt++;
            return addNode(root->left, val);
        }else{
            return addNode(root->right, val) + root->cnt + (root->val < val?1:0);
        }
    }
};
