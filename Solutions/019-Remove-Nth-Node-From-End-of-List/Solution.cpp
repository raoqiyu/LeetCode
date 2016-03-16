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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * scanPtr = head;
        ListNode * nthPtr = head;
        ListNode * prevPtr = NULL;
        int i = 0;
        // Because of that given n will always be valid, i do not do any kind of checking
        // Use two pointers, the fast pointer go n steps in advance, then the fast pointer and the slow pointer
        // go together, by doing this, when fast pointer run into the end of list, slow pointer will at the n-th node
        while (i < n){
            scanPtr = scanPtr->next;
            i++;
        }
        while(scanPtr != NULL){
            scanPtr = scanPtr->next;
            prevPtr = nthPtr;
            nthPtr  = nthPtr->next;
        }
        if(nthPtr == head)
            head = nthPtr->next;
        else
            prevPtr->next = nthPtr->next;
        delete nthPtr;
        return head;
    }
};
