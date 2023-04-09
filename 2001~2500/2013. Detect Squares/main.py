"""
Source: https://leetcode.com/problems/detect-squares/
Date: 2023/4/9
Skill:
Ref:
Runtime: 6419 ms, faster than 5.7%
Memory Usage: 33.4 MB, less than 11.87%
Time complexity:
Space complexity:
Constraints:
    0 <= x, y <= 1000
    At most 3000 calls in total will be made to add and count.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class DetectSquares:

    def __init__(self):
        self.cnt = [[0 for _ in range(1001)] for _ in range(1001)]
    def add(self, point: List[int]) -> None:
        self.cnt[point[0]][point[1]] += 1

    def count(self, point: List[int]) -> int:
        res, x, y = 0, point[0], point[1]
        for i in range(1001):
            side＿length = abs(x - i)
            if side＿length == 0:
                continue
            down, up = y - side＿length, y + side＿length
            if 0 <= down <= 1000:
                res += self.cnt[i][down] * self.cnt[x][down] * self.cnt[i][y]
            if 0 <= up <= 1000:
                res += self.cnt[i][up] * self.cnt[x][up] * self.cnt[i][y]

        return res


# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)


if __name__ == "__main__":
    s = Solution()
