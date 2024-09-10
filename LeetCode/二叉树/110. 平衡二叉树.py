# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def get_height(node):
            if node is None:
                return 0
            left_height = get_height(node.left)
            if left_height == -1:
                return -1
            right_height = get_height(node.right)
            if right_height == -1 or abs(left_height - right_height) > 1:
                return -1
            return max(left_height, right_height) + 1
        
        return get_height(root) != -1
            
# root = [1, 2, 2, 3, 3, None, None, 4, 4]
# Solution().isBalanced(root)