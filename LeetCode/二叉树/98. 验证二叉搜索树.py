# Definition for a binary tree node.
from math import inf
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# 前序        
class Solution:
    def isValidBST(self, root: Optional[TreeNode], left=-inf, right=inf) -> bool:
        if root is None:
            return True
        x = root.val
        return left < x < right and self.isValidBST(root.left, left, x) and self.isValidBST(root.right, x, right)
# 中序 
class Solution:
    pre = -inf
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        if not self.isValidBST(root.left):
            return False    
        if root.val <= self.pre:
            return False
        self.pre = root.val
        return self.isValidBST(root.right)

# 后序遍历
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def f(node):
            if node is None:
                return inf, -inf
            l_min, l_max = f(node.left)
            r_min, r_max = f(node.right)
            x = node.val
            if x <= l_max or x >= r_min:
                return -inf, inf
            return min(l_min, x), max(r_max, x)
        return f(root)[1] != inf