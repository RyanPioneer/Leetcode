"""
Source: https://leetcode.com/problems/flip-string-to-monotone-increasing/
Date: 2023/1/17
Skill:
Ref:
Runtime: 302 ms, faster than 65.7%
Memory Usage: 14.8 MB, less than 96.47%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict


class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        one_num, zero_num = 0, 0
        for letter in s:
            if letter == "0":
                zero_num += 1
            else:
                one_num += 1

        if one_num == 0 or zero_num == 0: return 0

        res = min(one_num, zero_num)

        cur_zero_num, cur_one_num = 0, 0
        for letter in s:
            if letter == "0":
                cur_zero_num += 1
            else:
                cur_one_num += 1
            res = min(res, cur_one_num + (zero_num - cur_zero_num))

        return res