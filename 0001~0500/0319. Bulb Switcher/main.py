"""
Source: https://leetcode.com/problems/bulb-switcher/
Date: 2023/4/27
Skill:
Ref:
Runtime: 51 ms, faster than 8.42%
Memory Usage: 16.2 MB, less than 34.9%
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
    def bulbSwitch(self, n: int) -> int:
        return int(math.sqrt(n))


if __name__ == "__main__":
    s = Solution()
