"""
Source: https://rb.gy/d5dj8
Date: 2023/8/26
Skill:
Runtime: 1689 ms, faster than 73.33%
Memory Usage: 69.54 MB, less than 6.67%
Time complexity:
Space complexity:
Constraints:
    1 <= fruits.length <= 10 ** 5
"""

import math
import sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        pos2num, cur_sum, left, right, sz, res = defaultdict(int), 0, max(0, startPos - k), startPos, max(fruits[-1][0], startPos), 0
        for pos, amount in fruits:
            pos2num[pos] = amount
        for i in range(left, right):
            if i in pos2num:
                cur_sum += pos2num[i]
        while right <= sz and left <= startPos:
            while right <= sz and min(startPos - left, right - startPos) * 2 + max(startPos - left,
                                                                                   right - startPos) <= k:
                if right in pos2num:
                    cur_sum += pos2num[right]
                right += 1
            res = max(res, cur_sum)
            if left in pos2num:
                cur_sum -= pos2num[left]
            left += 1
        return res


if __name__ == "__main__":
    s = Solution()
    fruits, startPos, k = [[0, 10000]], 200000, 200000
    res = s.maxTotalFruits(fruits, startPos, k)
    print(res)
