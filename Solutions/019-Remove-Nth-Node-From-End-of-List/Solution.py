# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        fastPtr  = head
        slowPtr = head
        prevPtr  = None
        while n > 0:
            fastPtr = fastPtr.next
            n -= 1
        while fastPtr !=  None:
            fastPtr, prevPtr, slowPtr = fastPtr.next, slowPtr, slowPtr.next
        if slowPtr == head:
            head = slowPtr.next
        else:
            prevPtr.next = slowPtr.next
        del slowPtr
        return head
