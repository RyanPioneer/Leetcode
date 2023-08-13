"""
Source: https://rb.gy/4of2y
Date: 2023/8/13
Skill:
Ref:
Runtime: 339 ms, faster than 75.25%
Memory Usage: 24.11 MB, less than 9.41%
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
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        left, bottom, right, top = rectangles[0][0], rectangles[0][1], rectangles[0][2], rectangles[0][3]
        area, sz, cnt = (top - bottom) * (right - left), len(rectangles), defaultdict(int)
        cnt[(left, bottom)] += 1
        cnt[(right, top)] += 1
        cnt[(left, top)] += 1
        cnt[(right, bottom)] += 1
        for i in range(1, sz):
            x1, y1, x2, y2 = rectangles[i][0], rectangles[i][1], rectangles[i][2], rectangles[i][3]
            area += (x2 - x1) * (y2 - y1)
            left = min(left, x1)
            right = max(right, x2)
            bottom = min(bottom, y1)
            top = max(top, y2)
            cnt[(x1, y1)] += 1
            cnt[(x2, y2)] += 1
            cnt[(x1, y2)] += 1
            cnt[(x2, y1)] += 1
        if area != (top - bottom) * (right - left):
            return False
        for key, val in cnt.items():
            if key == (left, bottom) or key == (right, top) or key == (left, top) or key == (right, bottom):
                if val != 1:
                    return False
            elif val != 2 and val != 4:
                return False
        return True


if __name__ == "__main__":
    s = Solution()
    rectangles = [[1, 1, 3, 3], [3, 1, 4, 2], [3, 2, 4, 4], [1, 3, 2, 4], [2, 3, 3, 4]]
    res = s.isRectangleCover(rectangles)
    print(res)
