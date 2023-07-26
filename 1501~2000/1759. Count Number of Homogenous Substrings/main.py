"""
Source: https://rb.gy/jm8v9
Date: 2023/7/26
Skill:
Ref:
Runtime: 149 ms, faster than 70.83%
Memory Usage: 17.57 MB, less than 15.63%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def countHomogenous(self, s: str) -> int:
        MOD = 10 ** 9 + 7
        res, cur_char, cur_num, sz = 1, s[0], 1, len(s)
        for i in range(1, sz):
            if s[i] == cur_char:
                cur_num += 1
                res += cur_num
            else:
                cur_char = s[i]
                cur_num = 1
                res += cur_num
        return res % MOD


if __name__ == "__main__":
    s = Solution()
