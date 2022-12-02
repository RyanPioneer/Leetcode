"""
Source: https://leetcode.com/problems/palindrome-number/
Date: 2022/2/18
Constraints: 
    -2^31 <= x <= 2^31 - 1
"""

class Solution:
    def isPalindrome(self, x: int) -> bool:
        s = str(x)
        s2 = str(s[::-1])
        return s == s2