#
# @lc app=leetcode.cn id=206 lang=python
#
# [206] 反转链表
#

# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        stack = []
        while(head != None):
            stack.append(head)
            head = head.next
        if stack == []:
            return None
        head = stack[-1]
        stack.pop()
        p = head
        while(stack != []):
            top = stack[-1]
            stack.pop()
            p.next = top
            p = p.next
        
        p.next = None
        return head
            

        
        
# @lc code=end

