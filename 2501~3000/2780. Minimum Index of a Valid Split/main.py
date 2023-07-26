"""
Source: https://rb.gy/iyeyf
Date: 2023/7/26
Skill:
Ref:
Runtime: 725 ms, faster than 63.00%
Memory Usage: 30.63 MB, less than 94.16%
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
    def minimumIndex(self, nums: List[int]) -> int:
        sz, target, freq = len(nums), 0, 0
        for num in nums:
            if num == target:
                freq += 1
            elif freq > 0:
                freq -= 1
            else:
                target = num
                freq += 1

        freq, cur_freq = 0, 0
        for num in nums:
            if num == target:
                freq += 1
        for i in range(sz - 1):
            if nums[i] == target:
                cur_freq += 1
            if cur_freq * 2 > i + 1 and (freq - cur_freq) * 2 > (sz - i - 1):
                return i
        return -1


if __name__ == "__main__":
    s = Solution()
