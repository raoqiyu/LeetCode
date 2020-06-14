# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        n_nodes = len(preorder)
        if n_nodes == 0:
            return None
        
        root = TreeNode(val=preorder[0])
        inorder2pos = {v:i for i,v in enumerate(inorder)}
        root_idx = inorder2pos[root.val]

        def build(pre_idx,  inorder_begin, inorder_end):
            if inorder_begin > inorder_end or pre_idx >= n_nodes:
                return None
            
            root = TreeNode(preorder[pre_idx])
            if inorder_begin == inorder_end:
                return root
            
            root_idx = inorder2pos[root.val]
            n_left = root_idx - inorder_begin
            
            root.left= build(pre_idx+1, inorder_begin, root_idx-1)
            root.right= build(pre_idx+n_left+1, root_idx+1, inorder_end)
            
            return root

        
        return build(0, 0, n_nodes-1)
        
        
