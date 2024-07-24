#
# @lc app=leetcode.cn id=25 lang=python3
#
# [25] K 个一组翻转链表
#

# @lc code=start
# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        n = 0
        cur = head
        while cur:
            cur = cur.next
            n += 1
            
        dummpy = ListNode(next=head)
        p0 = dummpy
        pre = None
        cur = p0.next
        while n >= k:
            n -= k
            for _ in range(k):
                nex = cur.next
                cur.next = pre
                pre = cur
                cur = nex
            
            nex = p0.next
            p0.next.next = cur
            p0.next = pre
            p0 = nex
        return dummpy.next
            
# @lc code=end

