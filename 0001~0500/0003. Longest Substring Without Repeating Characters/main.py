"""
Source: https://leetcode.com/problems/longest-substring-without-repeating-characters/
Date: 2022/2/18
skill: Sliding Window  https://ithelp.ithome.com.tw/articles/10185006
0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        arr = [s[0]]
        i = 1
        start = 0
        ans = 1
        while i < len(s):
            if s[i] in arr:
                if i - start > ans:
                    ans = i - start
                while s[start] != s[i]:
                    arr.remove(s[start])
                    start += 1
                start += 1
            else:
                arr.append(s[i])
            i += 1
        if i - start > ans:
            ans = i - start
        return ans