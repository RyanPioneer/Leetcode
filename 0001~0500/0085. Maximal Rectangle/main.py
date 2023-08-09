"""
Source: https://rb.gy/od648
Date: 2023/8/9
Skill:
Ref:
Runtime: 294 ms, faster than 56.85%
Memory Usage: 17.78 MB, less than 41.46%
Time complexity:
Space complexity:
Constraints:
    1 <= row, cols <= 200
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        m, n, res = len(matrix), len(matrix[0]), 0
        def find_largest_rectangle_area(height):
            sz, area = len(height), 0
            prev_smaller, next_smaller = [-1 for _ in range(sz)], [sz for _ in range(sz)]
            stack1, stack2 = [sz - 1], [0]
            for i in range(1, sz):
                while stack1 and height[sz - 1 - i] < height[stack1[-1]]:
                    prev_smaller[stack1[-1]] = sz - 1 - i
                    stack1.pop()
                stack1.append(sz - 1 - i)
                while stack2 and height[i] < height[stack2[-1]]:
                    next_smaller[stack2[-1]] = i
                    stack2.pop()
                stack2.append(i)
            for i in range(sz):
                area = max(area, height[i] * (next_smaller[i] - prev_smaller[i] - 1))
            return area

        cur_height = [0 for _ in range(n)]
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == "1":
                    cur_height[j] += 1
                else:
                    cur_height[j] = 0
            res = max(res, find_largest_rectangle_area(cur_height))
        return res


if __name__ == "__main__":
    s = Solution()
