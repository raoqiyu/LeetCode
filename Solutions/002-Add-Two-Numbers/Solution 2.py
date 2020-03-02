# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        x_node, y_node = l1, l2
        root = ListNode(-1)
        z_node,z_prev = root, 0
        while x_node and y_node:
            tmp = x_node.val + y_node.val + z_prev
            z_prev, tmp = tmp//10, tmp%10
            z_node.next = ListNode(tmp)
            z_node = z_node.next
            x_node = x_node.next
            y_node = y_node.next
            
        rest_node = None
        if x_node:
            rest_node = x_node
        elif y_node:
            rest_node = y_node
            
        while rest_node:
            tmp = rest_node.val + z_prev
            z_prev, tmp = tmp//10, tmp%10
            z_node.next = ListNode(tmp)
            z_node = z_node.next
            rest_node = rest_node.next
        
        if z_prev > 0:
            z_node.next = ListNode(z_prev)
        
        return root.next

        
            
