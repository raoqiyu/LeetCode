/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL || root->left == NULL)
            return ;
        
        // connect root's left child to its right node
        root->left->next = root->right;
        // connect root's right child to the next right node
        if(root->next)
            root->right->next = root->next->left;
            
        // recurrsive connect root's child
        connect(root->left);
        connect(root->right);
        
        return;
    }
};
