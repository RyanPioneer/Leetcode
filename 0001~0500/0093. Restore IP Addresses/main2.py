"""
Source: https://leetcode.com/problems/restore-ip-addresses/
Date: 2023/1/21
Skill: Iterative
Ref:
Runtime: 23 ms, faster than 99.72%
Memory Usage: 13.9 MB, less than 79.81%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 20
    s consists of digits only.
"""

from typing import List, Optional

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res, sz = [], len(s)

        def check_valid(string):
            if len(string) > 3 or len(string) == 0: return False
            elif string[0] == "0" and len(string) > 1: return False
            elif int(string) > 255: return False
            else: return True

        for len1 in range(max(1, sz-9), min(3, sz-3)+1):
            if not check_valid(s[:len1]): continue
            for len2 in range(max(1, sz-len1-6), min(3, sz-len1-2)+1):
                if not check_valid(s[len1:len1+len2]): continue
                for len3 in range(max(1, sz-len1-len2-3), min(3, sz-len1-len2-1)+1):
                    len4 = sz-len1 - len2 - len3
                    if check_valid(s[len1+len2:len1+len2+len3]) and check_valid(s[len1+len2+len3:len1+len2+len3+len4]):
                        res.append(s[:len1]+"."+s[len1:len1+len2]+"."+s[len1+len2:len1+len2+len3]+"."+s[len1+len2+len3:len1+len2+len3+len4])

        return res


if __name__ == "__main__":
    string = "10101010"
    s = Solution
    res = s.restoreIpAddresses(s, string)