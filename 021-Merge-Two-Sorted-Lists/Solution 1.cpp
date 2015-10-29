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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode  l3Head(-1);
        ListNode * l3 = &l3Head;
        while( 1){
            if (l1 == NULL){
                l3->next = l2;
                break;
            }else if(l2 == NULL){
                l3->next = l1;
                break;;
            }else if( l1->val <= l2->val){
                l3->next = l1;
                l1 = l1->next;
                l3 = l3->next;
                l3->next = NULL;
            }else {
                l3->next = l2;
                l2 = l2->next;
                l3 = l3->next;
                l3->next = NULL;
            }
        }
            
        return l3Head.next;
    }
};
