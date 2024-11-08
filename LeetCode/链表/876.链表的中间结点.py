#
# @lc app=leetcode.cn id=876 lang=python
#
# [876] 链表的中间结点
#

# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        slow = head
        fast = head
        while fast and fast.next:
            fast = fast.next.next 
            slow = slow.next
        return slow
        
        
# @lc code=end

