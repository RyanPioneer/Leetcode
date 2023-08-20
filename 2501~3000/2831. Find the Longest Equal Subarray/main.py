"""
Source: https://rb.gy/b64dd
Date: 2023/8/20
Skill:
Runtime: 1589 ms, faster than 100.00%
Memory Usage: 39.7 MB, less than 100.00%
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


class Solution:
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
        res, freq, prev_pos, cost, total_cost, sz = 1, defaultdict(int), defaultdict(int), defaultdict(list),defaultdict(int), len(nums)
        for i in range(sz):
            num = nums[i]
            if num not in freq:
                freq[num] = 1
                prev_pos[num] = i
                total_cost[num] = 0
            else:
                cur_cost = i - prev_pos[num] - 1
                prev_pos[num] = i
                freq[num] += 1
                total_cost[num] += cur_cost
                cost[num].append(cur_cost)
                while total_cost[num] > k:
                    total_cost[num] -= cost[num].pop(0)
                    freq[num] -= 1
                res = max(res, freq[num])
        return res


if __name__ == "__main__":
    s = Solution()
