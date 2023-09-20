//
// Created by lbyang on 23-9-21.
//
#include <bits/stdc++.h>
using namespace std;

std::string convertToLowercaseAndRemoveNonAlphanumeric(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (isalnum(c)) {  // 检查字符是否为字母或数字
            result += tolower(c);  // 将字符转换为小写并追加到结果字符串
        }
    }
    return result;
}


class Solution {
public:
    bool isPalindrome(string s) {
        s = convertToLowercaseAndRemoveNonAlphanumeric(s);
        int l = 0, r = s.size()-1;
        bool flag = true;
        while (l <= r) {
            if (s[l] != s[r]) {
                flag = false;
                break;
            }
            l++;
            r--;
        }
        return flag;
    }
};

