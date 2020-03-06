# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        vals = []
        if not root:
            return vals
        lvl_vals, lvl_nodes = [], deque()
        lvl_nodes.append(root)
        depth = 0
        while lvl_nodes:
            n_nodes = len(lvl_nodes)
            for _ in range(n_nodes):
                node = lvl_nodes.popleft()
                lvl_vals.append(node.val)
                if node.left:
                    lvl_nodes.append(node.left)
                if node.right:
                    lvl_nodes.append(node.right)
            if lvl_vals:
                if depth % 2 != 0:
                    lvl_vals.reverse() 
                vals.append(lvl_vals)
                lvl_vals= []
                depth += 1
                
            
        return vals
        
        
        
        
