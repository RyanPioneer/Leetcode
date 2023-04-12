"""
Source: https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/
Date: 2023/4/12
Skill: Backtracking
Ref:
Runtime: 35 ms, faster than 72.96%
Memory Usage: 13.8 MB, less than 58.56%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 20
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def splitString(self, s: str) -> bool:
        sz = len(s)

        def back_tracking(idx, prev_num):
            nonlocal sz
            if idx == sz:
                return True
            for length in range(1, sz - idx + 1):
                num = int(s[idx: idx + length])
                if num + 1 == prev_num and back_tracking(idx + length, num):
                    return True

            return False

        for length in range(1, sz):
            first_num = int(s[:length])
            if back_tracking(length, first_num):
                return True
        return False


if __name__ == "__main__":
    s = Solution()
