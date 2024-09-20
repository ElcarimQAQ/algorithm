# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        x = root.val
        if p.val < x and q.val < x:
            return self.lowestCommonAncestor(root.left, p, q)
        if p.val > x and q.val > x :
            return self.lowestCommonAncestor(root.right, p, q)
        return root

node1 = TreeNode(6)
node2 = TreeNode(2)
node3 = TreeNode(8)
node4 = TreeNode(0)
node5 = TreeNode(4)
node6 = TreeNode(7)
node7 = TreeNode(9)
node8 = TreeNode(3)
node9 = TreeNode(5)
node1.left = node2
node1.right = node3
node2.left = node4
node2.right = node5
node3.left = node6
node3.right = node7
node5.left = node8
node5.right = node9
print(Solution().lowestCommonAncestor(node1, node2, node5))

        
            