# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # Step 1: get all values
        val = []
        while l1 is not None:
            val.append(l1.val); l1 =  l1.next 
        while l2 is not None:
            val.append(l2.val); l2 = l2.next 
        # Step 2: sort the values array
        val.sort()
        # Step 3: Construct the result linked list
        ret = ListNode(-1)
        ptr = ret
        for v in val:
            ptr.next = ListNode(v)
            ptr = ptr.next
        return ret.next
            
        
