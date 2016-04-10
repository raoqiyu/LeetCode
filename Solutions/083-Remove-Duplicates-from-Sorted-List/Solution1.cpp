/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        while(ptr != NULL){
            while(ptr->next && ptr->val == ptr->next->val){
                ListNode * temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
            }
            ptr = ptr->next;
        }
        return head;
        
    }
};
