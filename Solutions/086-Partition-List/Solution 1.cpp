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
    ListNode* partition(ListNode* head, int x) {
        // Two pointers
        // ptr1 : the end of node which's value is less than x
        // ptr2 : the end of node which's value is greater then or equal to x
        ListNode *dummy1 = new ListNode(-1), *dummy2 = new ListNode(-1);
        dummy1->next = head;
        ListNode *ptr1 = dummy1, *ptr2 = dummy2;

        while(ptr1->next){
            if(ptr1->next->val >= x){
                ptr2->next = ptr1->next;
                ptr1->next = ptr1->next->next;
                ptr2 = ptr2->next;
                ptr2->next = NULL;
            }else{
                ptr1 = ptr1->next;
            }
        }
        ptr1->next = dummy2->next;
        return dummy1->next;
    }
};
