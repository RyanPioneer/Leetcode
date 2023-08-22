"""
Source: https://rb.gy/mp4p2
Date: 2023/8/22
Skill:
Ref:
Runtime: 619 ms, faster than 89.02%
Memory Usage: 26.93 MB, less than 81.57%
Time complexity:
Space complexity:
Constraints:
    1 <= boxes.length <= 100
    1 <= boxes[i] <= 100
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right
from functools import cache


class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        @cache
        def dfs(left, right, same_val_after):
            if left > right:
                return 0
            if left == right:
                return (same_val_after + 1) ** 2
            i, res = right, 0
            while i >= left and boxes[i] == boxes[right]:
                i -= 1
                same_val_after += 1
            res = dfs(left, i, 0) + same_val_after ** 2
            for j in range(i, left - 1, -1):
                if boxes[j] != boxes[right]:
                    continue
                if boxes[j] == boxes[right] and boxes[j + 1] == boxes[right]:
                    continue
                res = max(res, dfs(left, j, same_val_after) + dfs(j + 1, i, 0))
            return res

        return dfs(0, len(boxes) - 1, 0)


if __name__ == "__main__":
    s = Solution()
