
#
# Note: 类名、方法名、参数名已经指定，请勿修改
#
#
# 
# @param s string字符串  
# @return string字符串
#
class Solution:
    def reverseWords(self, s) :
        return " ".join(s.split()[::-1])

# print(Solution().reverseWords("I am a student."))