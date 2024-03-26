#
# @lc app=leetcode.cn id=71 lang=python
#
# [71] 简化路径
#

# @lc code=start
class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = []
        s1 = ''
        for i in range(0, len(path)):
            if path[i] == '/':
                if(s1 == '..'):
                    if(len(stack) != 0):
                        stack.pop()
                elif(s1 != '.' and s1 != ''):
                    stack.append(s1)
                s1 = ''   
            else:
                s1 = s1+path[i]
        # print(s1)
        if(s1 != ''):
            if s1 == '..' and len(stack) != 0:
                stack.pop()
            elif(s1 != '.' and s1 != '..'):
                stack.append(s1)
        
        if(len(stack) == 0):
            return '/'
        ans = ''
        for i in range(0, len(stack)):
            ans = ans +f'/{stack[i]}'
        return ans
            
# @lc code=end

if __name__ == "__main__":
    s = Solution()
    print(s.simplifyPath("/a//b////c/d//././/.."))
