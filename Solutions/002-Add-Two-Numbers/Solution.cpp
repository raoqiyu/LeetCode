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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode(-1);
        ListNode *curr = ret;
        int carry = 0, sum;
        
        while(l1  && l2){
            // Calculate the sum
            sum = carry + l1->val + l2->val;
            // Update carry
            carry = (sum>=10)?1:0;
            // Update sum if it is greater than 10
            sum = sum % 10;
            curr->next =  new ListNode(sum);
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            // Calculate the sum
            sum = carry + l1->val;
            // Update carry
            carry = (sum>=10)?1:0;
            // Update sum if it is greater than 10
            sum = sum % 10;
            curr->next =  new ListNode(sum);
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2){
            // Calculate the sum
            sum = carry + l2->val;
            // Update carry
            carry = (sum>=10)?1:0;
            // Update sum if it is greater than 10
            sum = sum % 10;
            curr->next =  new ListNode(sum);
            curr = curr->next;
            l2 = l2->next;
        }
        if (carry> 0 ){
            curr->next = new ListNode(carry);
        }
        return ret->next;
    }
};
