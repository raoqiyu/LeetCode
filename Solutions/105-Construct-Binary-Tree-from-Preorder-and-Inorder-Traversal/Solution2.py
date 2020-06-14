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
        left_inorder, right_inorder = [], []
        is_left = True
        for v in inorder:
            if v == preorder[0]:
                is_left=False
            elif is_left:
                left_inorder.append(v)
            else:
                right_inorder.append(v)
        n_left= len(left_inorder)
        left_preorder = preorder[1:1+n_left]
        right_preorder = preorder[1+n_left:]

        root.left = self.buildTree(left_preorder, left_inorder)
        root.right = self.buildTree(right_preorder, right_inorder)
        
        return root
        
        
