"""
Source: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
Date: 2023/7/3
Skill:
Ref:
Runtime: 172 ms, faster than 53.10%
Memory Usage: 17.3 MB, less than 94.96%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        left_num = max(left) if len(left) > 0 else 0
        right_num = n - min(right) if len(right) > 0 else 0
        return max(left_num, right_num)


if __name__ == "__main__":
    s = Solution()
