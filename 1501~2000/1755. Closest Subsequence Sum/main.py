"""
Source: https://rb.gy/h8vgw
Date: 2023/7/25
Skill:
Ref:
Runtime: 10269 ms, faster than 5.08%
Memory Usage: 63.9 MB, less than 99.28%
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
    def minAbsDifference(self, nums: List[int], goal: int) -> int:
        pos, neg = 0, 0
        for num in nums:
            if num > 0:
                pos += num
            else:
                neg += num
        if pos < goal:
            return goal - pos
        if neg > goal:
            return neg - goal
        sz, potential_sum, res = len(nums), [], abs(goal)
        for i in range(1 << (sz // 2)):
            cur_sum = 0
            for j in range(sz // 2):
                if i & (1 << j):
                    cur_sum += nums[j]
            potential_sum.append(cur_sum)

        potential_sum.sort()
        length = sz - sz // 2
        for i in range(1 << length):
            cur_sum = 0
            for j in range(length):
                if i & (1 << j):
                    cur_sum += nums[sz // 2 + j]
            pos = bisect_left(potential_sum, goal - cur_sum)
            if pos < len(potential_sum):
                res = min(res, abs(goal - cur_sum - potential_sum[pos]))
            pos -= 1
            if pos >= 0:
                res = min(res, abs(goal - cur_sum - potential_sum[pos]))

        return res


if __name__ == "__main__":
    s = Solution()
