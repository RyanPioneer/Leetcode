"""
Source: https://rb.gy/s1dx8
Date: 2023/7/14
Skill:
Ref:
Runtime: 2829 ms, faster than 83.71%
Memory Usage: 33.98 MB, less than 72.45%
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
    def longestArithSeqLength(self, nums: List[int]) -> int:
        dp, sz, res = [defaultdict(int) for _ in range(len(nums))], len(nums), 1
        for i in range(sz):
            for j in range(i):
                diff = nums[i] - nums[j]
                if diff in dp[j]:
                    dp[i][diff] = dp[j][diff] + 1
                else:
                    dp[i][diff] = 2
                res = max(res, dp[i][diff])
        return res


if __name__ == "__main__":
    s = Solution()
