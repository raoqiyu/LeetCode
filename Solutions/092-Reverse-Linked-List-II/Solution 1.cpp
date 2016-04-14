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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *ptr1 = &dummy;
        n -= m;
        while(--m){
            ptr1 = ptr1->next;
        }
        ListNode *ptr2 = ptr1->next, *tmp;
        while(n--){
            tmp = ptr2->next;
            ptr2->next = ptr2->next->next;
            tmp->next = ptr1->next;
            ptr1->next = tmp;
        }
        return dummy.next;
    }
};
