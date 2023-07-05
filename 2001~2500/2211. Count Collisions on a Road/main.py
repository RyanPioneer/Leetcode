"""
Source: https://leetcode.com/problems/count-collisions-on-a-road/
Date: 2023/7/3
Skill:
Ref:
Runtime: 211 ms, faster than 68.52%
Memory Usage: 17.3 MB, less than 100%
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
    def countCollisions(self, directions: str) -> int:
        right, res, stay = 0, 0, 0
        for i in directions:
            if i == "L":
                if right != 0:
                    res += right + 1
                    right = 0
                elif res != 0 or stay != 0:
                    res += 1
            elif i == "S":
                stay += 1
                if right > 0:
                    res += right
                    right = 0
            else:
                right += 1
        return res


if __name__ == "__main__":
    s = Solution()
