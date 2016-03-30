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
    ListNode* rotateRight(ListNode* head, int k) {
        // Two pointers
        if(head == NULL || k == 0)
            return head;
        
        int size = 0;
        ListNode* ptr1 = head;
        // get the size of link list
        while(ptr1->next != NULL){
            size++;
            ptr1 = ptr1->next;
        }
        k = k % ++size;
        if(k == 0)
            return head;
            
        int n = size-k; 
        ListNode* ptr2 = head;
        // find the new head position
        while(n-- > 1){
            ptr2 = ptr2->next;
        }
        
        ListNode* newhead = ptr2->next;
        ptr1->next = head;
        ptr2->next = NULL;
        
        return newhead;
    }
};
