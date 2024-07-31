#
# @lc app=leetcode.cn id=143 lang=python3
#
# [143] 重排链表
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# @lc code=end

class Solution:
    def reverse(self, head):
        p = head
        pre = None
        while p:
            nex = p.next
            p.next = pre
            pre = p
            p = nex
        return pre

    def find(self, head):
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow

    def reorderList(self , head):
        # write code here
        mid = self.find(head)
        head2 = self.reverse(mid)
        mid.next = None
        while head2.next:
            nex1 = head.next
            nex2 = head2.next
            head.next = head2
            head2.next = nex1
            head = nex1
            head2 = nex2
             



