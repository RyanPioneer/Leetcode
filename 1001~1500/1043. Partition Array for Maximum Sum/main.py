"""
Source: https://leetcode.com/problems/partition-array-for-maximum-sum/
Date: 2023/3/29
Skill:
Runtime: 472 ms, faster than 93.50%
Memory Usage: 13.8 MB, less than 100%
Time complexity:
Space complexity:
Constraints:
    1 <= arr.length <= 500
    0 <= arr[i] <= 10^9
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        arr.insert(0, 0)
        dp, sz = [0 for _ in range(len(arr))], len(arr)
        for i in range(1, sz):
            cur_max = arr[i]
            for j in range(i, max(0, i - k), -1):
                cur_max = max(arr[j], cur_max)
                dp[i] = max(dp[i], dp[j - 1] + cur_max * (i - j + 1))

        return dp[sz - 1]


if __name__ == "__main__":
    s = Solution()
    arr = [1, 15, 7, 9, 2, 5, 10]
    k = 3
    res = s.maxSumAfterPartitioning(arr, k)  # 84
