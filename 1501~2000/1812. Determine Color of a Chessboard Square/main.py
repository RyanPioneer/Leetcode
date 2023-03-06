"""
Source: https://leetcode.com/problems/determine-color-of-a-chessboard-square/
Date: 2023/3/5
Skill:
Runtime: 31 ms, faster than 66.70%
Memory Usage: 13.9 MB, less than 45.35%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        return (ord(coordinates[0]) - ord("a") + int(coordinates[1]) - 1) % 2


if __name__ == "__main__":
    s = Solution()
