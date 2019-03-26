# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ret = []
        stack = []
        
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            
            if stack:
                root = stack.pop()
                ret.append(root.val)
                root = root.right
                
        return ret
