"""
Source: https://leetcode.com/problems/restore-ip-addresses/
Date: 2023/1/21
Skill: Backtracking
Ref:
Runtime: 31 ms, faster than 95.31%
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
        self.res, sz = [], len(s)

        def backtrack(idx, remaining_num):
            local_res = []
            if idx >= sz: return local_res
            if remaining_num == 1:
                if sz-idx > 3 or (sz-idx > 1 and s[idx] == "0") or int(s[idx:sz]) > 255: return local_res
                else: return [s[idx:sz]]

            if s[idx] == "0":
                if (sz-idx-1)/(remaining_num-1) <= 3:
                    next_res = backtrack(idx + 1, remaining_num - 1)
                    if len(next_res) > 0:
                        for res in next_res:
                            local_res.append(s[idx]+"."+res)
                    if remaining_num == 4: self.res += local_res
                    else: return local_res
                else:
                    return local_res

            else:
                for i in range(3):
                    if (sz-(idx+i)-1)/(remaining_num-1) <= 3 and int(s[idx:idx+i+1]) <= 255:
                        next_res = backtrack(idx + i + 1, remaining_num - 1)
                        if len(next_res) > 0:
                            for res in next_res:
                                local_res.append(s[idx:idx+i+1] + "." + res)
                if remaining_num == 4: self.res += local_res
                else: return local_res

        backtrack(0, 4)
        return self.res


if __name__ == "__main__":
    string = "10101010"
    s = Solution
    res = s.restoreIpAddresses(s, string)