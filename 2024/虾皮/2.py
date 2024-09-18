
#
# Note: 类名、方法名、参数名已经指定，请勿修改
#
#
# 
# @param preOrder string字符串  
# @param middleOrder string字符串  
# @return string字符串
#
class Solution:
    def getLRD(self, preOrder, middleOrder) :
        # 先序遍历的第一个节点是根节点
        # 中序遍历的根节点左边是左子树，右边是右子树
        # 递归
        # 输出后序遍历
        if preOrder == "":
            return ""
        root = preOrder[0]
        root_index = middleOrder.index(root)
        left = self.getLRD(preOrder[1:root_index+1], middleOrder[:root_index])
        right = self.getLRD(preOrder[root_index+1:], middleOrder[root_index+1:])
        return left + right + root 
        
        
print(Solution().getLRD("01234","10324"))
        
