"""
Source: https://leetcode.com/problems/stone-game-ix/
Date: 2023/4/7
Skill:
Ref:
Runtime: 1924 ms, faster than 16%
Memory Usage: 122.3 MB, less than 12%
Time complexity:
Space complexity:
Constraints:
    1 <= stones.length <= 10^5
    1 <= stones[i] <= 10^4
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        nums = [0 for _ in range(3)]
        for stone in stones:
            nums[stone % 3] += 1

        def calculate(remainder, total, turn):
            if sum(remainder) == 0:
                return False if turn == 0 else True
            if remainder[0] > 0:
                remainder[0] -= 1
                return not calculate(remainder, total, (turn + 1) % 2)
            if total == 1:
                if remainder[1] == 0:
                    return False
                else:
                    remainder[1] -= 1
                    return not calculate(remainder, 2, (turn + 1) % 2)
            else:
                if remainder[2] == 0:
                    return False
                else:
                    remainder[2] -= 1
                    return not calculate(remainder, 1, (turn + 1) % 2)

        nums2 = list(nums)
        if nums[1] > 0:
            nums[1] -= 1
            if not calculate(nums, 1, 1):
                return True

        if nums2[2] > 0:
            nums2[2] -= 1
            if not calculate(nums2, 2, 1):
                return True

        return False


if __name__ == "__main__":
    s = Solution()
