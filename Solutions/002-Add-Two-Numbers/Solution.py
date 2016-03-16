# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        # Firstly,  store the numbers
        ret_numbers = []
        while l1 and l2:
            ret_numbers.append(l1.val + l2.val)
            l1 = l1.next; l2 = l2.next
        while l1:
            ret_numbers.append(l1.val)
            l1 = l1.next
        while l2:
            ret_numbers.append(l2.val)
            l2 = l2.next
            
        carry = 0
        for i in range(len(ret_numbers)):
            ret_numbers[i] += carry
            if ret_numbers[i] >= 10:
                carry = 1
                ret_numbers[i] = ret_numbers[i] - 10
            else:
                carry = 0
        if carry > 0:
            ret_numbers.append(carry)

        # Secondly, construct the ListNode list
        ret = ListNode(-1)
        curr = ListNode(-1)
        # result ListNode starts from ret.next
        ret.next = curr
        for val in ret_numbers:
            temp = ListNode(val)
            temp.next = None
            curr.next = temp
            curr = curr.next
        return ret.next.next
