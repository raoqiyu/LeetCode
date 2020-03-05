# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        serialized = []
        if not root:
            return ''
        
        queue,q_index,q_cnt = [root], 0, 1
        
        while q_cnt > 0:
            curr,q_index,q_cnt = queue[q_index], q_index+1, q_cnt-1
            
            if curr is None:
                serialized.append("NULL")
                continue
                
            serialized.append(str(curr.val))
            
            queue.append(curr.left)
            queue.append(curr.right)
            q_cnt += 2
        return ','.join(serialized)
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if len(data) == 0:
            return None
        
        nodes = data.split(',')
        n_nodes = len(nodes)
        
        root = TreeNode(int(nodes[0]))
        i = 1
        queue,q_index = [root], 0
        while i < n_nodes:
            curr,q_index = queue[q_index], q_index+1
            
            val_left,val_right = nodes[i], nodes[i+1]
            
            if val_left != "NULL":
                node_left = TreeNode(int(val_left))
                curr.left = node_left
                queue.append(node_left)
                
            if val_right != "NULL":
                node_right = TreeNode(int(val_right))
                curr.right = node_right
                queue.append(node_right)
            
            i += 2
                
        return root
                
            
        
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
