# 是否平衡二叉树， 平衡二叉树任何左右子树深度差不超过1

class TreeNode:
    def __init__(self, left=None, right= None) -> None:
        self.left = left
        self.right = right
        
def height(node):
    if node is None:
        return 0
    left_height = height(node.left)
    right_height = height(node.right)
    
    if abs(left_height - right_height) > 1:
        return -1
    
    return max(left_height, right_height) + 1
    

def slove(root):
    return height(root) != -1
    
    