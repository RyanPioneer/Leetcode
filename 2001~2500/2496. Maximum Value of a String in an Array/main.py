"""
Source: https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/
Date: 2023/2/18
Skill:
Ref:
Runtime: 32 ms, faster than 80.72%
Memory Usage: 13.8 MB, less than 94.46%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        res = 0
        for word in strs:
            flag = True
            for c in word:
                if not c.isdigit():
                    res = max(res, len(word))
                    flag = False
                    break

            if flag:
                res = max(res, int(word))

        return res


if __name__ == "__main__":
    s = Solution