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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * h = head;
        if(k == 1) return head;
        int cnt = 0,size = 0;
        // reverse the first k nodes
        while(h){
            h = h->next;
            size++;
        }
        if(size < k) return head;
        
        // reverse  nodes
        h = head;
        head = reverse(h,k);
        
        int i = k;
        h = head;
        ListNode * curr;
        while(i + k <= size){
            cnt = k;
            while(--cnt) h = h->next;
            curr = h->next;
            curr = reverse(curr, k);
            h->next = curr;
            h = h->next;
            i += k;
        }
        return head;
    }
    
private:
    ListNode * reverse(ListNode *start, int size)
    {
        ListNode *curr=start, *prev=NULL, *next;
        while(size--){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        start->next = curr;
        return prev;
    }
};
