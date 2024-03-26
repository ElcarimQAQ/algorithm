#
# @lc app=leetcode.cn id=20 lang=python
#
# [20] 有效的括号
#

# @lc code=start
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        print(s)
        for item in s:
            print(item)
            if item in ['(', '{','[']:
                stack.append(item)
                continue
            if stack == []:
                return False
            top = stack.pop()
            if item == ')' and top != '(':
                return False
            if item == '}' and top != '{':
                return False
            if item == ']' and top != '[':
                return False
            
        if len(stack) == 0:
            return True
        return False
                


if __name__ != '__main__':
    s = Solution()
    print(s.isValid('()'))

