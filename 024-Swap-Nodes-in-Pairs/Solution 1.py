# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # Scan the linked list, each time we meet a node , 
        #   swap the value of this node and the node after this 
        ptr = head
        while ptr and ptr.next:
            ptr.val, ptr.next.val, ptr= ptr.next.val, ptr.val, ptr.next.next
        return head
