# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: ListNode
        :type left: int
        :type right: int
        :rtype: ListNode
        """
        # 头节点， left为1时
        dummy = ListNode(next=head)
        p = dummy
        for _ in range(left-1):
           p = p.next
           
        pre = None
        cur = p.next # left 位置 
        for _ in range(right - left + 1):
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
             
        p.next.next = cur
        p.next =  pre
        
        return dummy.next
        
       