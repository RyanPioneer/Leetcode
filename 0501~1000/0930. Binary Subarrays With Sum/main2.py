"""
Source: https://rb.gy/gmemb
Date: 2023/7/10
Skill: Prefix sum
Ref:
Runtime: 307 ms, faster than 43.37%
Memory Usage: 20.4 MB, less than 17.96%
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
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        presum, sz, cur_sum, res = defaultdict(int), len(nums), 0, 0
        presum[0] = 1
        for i in range(sz):
            cur_sum += nums[i]
            res += presum[cur_sum - goal]
            presum[cur_sum] += 1
        return res


if __name__ == "__main__":
    s = Solution()
