"""
Source: https://leetcode.com/problems/longest-common-prefix/
Date: 2022/2/18
Constraints: 
    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lower-case English letters.
"""

from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = ""
        i = 0
        while 1:
            if i < len(strs[0]):
                ch = strs[0][i]
            else:
                break
            valid = True
            for str in strs:
                if i >= len(str) or ch != str[i]:
                    valid = False
                    break
            if valid == True:
                ans += ch
                i += 1
            else:
                break
        return ans
                
        