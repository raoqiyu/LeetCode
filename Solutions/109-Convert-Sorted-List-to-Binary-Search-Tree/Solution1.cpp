/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        // Two pointers to find middle node
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);
        
        ListNode *ptr1 = head, *ptr2 = head, *ptr2_prev = head;
        while(ptr1 != NULL && ptr1->next != NULL){
            ptr1 = ptr1->next->next;
            ptr2_prev = ptr2;
            ptr2 = ptr2->next;
        }
        TreeNode* root = new TreeNode(ptr2->val);
        ptr2_prev->next = NULL;
        root->left  = sortedListToBST(head);
        root->right = sortedListToBST(ptr2->next);
        
        return root;
    }
};
