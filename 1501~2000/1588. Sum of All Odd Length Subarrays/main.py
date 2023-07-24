"""
Source: https://rb.gy/ov0qo
Date: 2023/7/24
Skill:
Ref:
Runtime: 72 ms, faster than 63.24%
Memory Usage: 16.37 MB, less than 40.42%
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
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        dp, res, sz = [0 for _ in range(len(arr))], 0, len(arr)
        for i in range(sz):
            for j in range(i, 0, -1):
                dp[j] = dp[j-1] + arr[i]
                if j % 2 == 0:
                    res += dp[j]
            dp[0] = arr[i]
            res += dp[0]

        return res


if __name__ == "__main__":
    s = Solution()
