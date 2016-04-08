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
        ListNode* dummy = new ListNode(0);
        dummy->next = head; head = dummy;
        while(head->next && head->next->next){
            if(head->next->val == head->next->next->val){
                int val = head->next->val;
                while(head->next && head->next->val == val)
                    head->next = head->next->next;
            }else{
                head = head->next;
            }
        }
        return dummy->next;
    }
};
